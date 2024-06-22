// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Wacom Penabled Driver for I2C
 *
 * Copyright (c) 2011 - 2013 Tatsunosuke Tobita, Wacom.
 * <tobita.tatsunosuke@wacom.co.jp>
 */

#include <linux/module.h>
#include <linux/input.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <asm/unaligned.h>

#define CST816S_NAME "cst816s_i2c"
#define CST816S_QUERY_SIZE 6

enum GESTURE {
  NONE = 0x00,
  SWIPE_UP = 0x01,
  SWIPE_DOWN = 0x02,
  SWIPE_LEFT = 0x03,
  SWIPE_RIGHT = 0x04,
  SINGLE_CLICK = 0x05,
  DOUBLE_CLICK = 0x0B,
  LONG_PRESS = 0x0C

};

char * gesture(u8 gestureID) {
  switch (gestureID) {
    case NONE:
      return "NONE";
      break;
    case SWIPE_DOWN:
      return "SWIPE DOWN";
      break;
    case SWIPE_UP:
      return "SWIPE UP";
      break;
    case SWIPE_LEFT:
      return "SWIPE LEFT";
      break;
    case SWIPE_RIGHT:
      return "SWIPE RIGHT";
      break;
    case SINGLE_CLICK:
      return "SINGLE CLICK";
      break;
    case DOUBLE_CLICK:
      return "DOUBLE CLICK";
      break;
    case LONG_PRESS:
      return "LONG PRESS";
      break;
    default:
      return "UNKNOWN";
      break;
  }
}

typedef enum
{
	CST816_GestureID = 0x01,
	CST816_FingerNum,
	CST816_XposH,
	CST816_XposL,
	CST816_YposH,
	CST816_YposL,

	CST816_ChipID = 0xA7,
	CST816_ProjID,
	CST816_FwVersion,
	CST816_MotionMask,

	CST816_BPC0H = 0xB0,
	CST816_BPC0L,
	CST816_BPC1H,
	CST816_BPC1L,

	CST816_IrqPluseWidth = 0xED,
	CST816_NorScanPer,
	CST816_MotionSlAngle,
	CST816_LpScanRaw1H =0XF0,
	CST816_LpScanRaw1L,
	CST816_LpScanRaw2H,
	CST816_LpScanRaw2L,
	CST816_LpAutoWakeTime,
	CST816_LpScanTH,
	CST816_LpScanWin,
	CST816_LpScanFreq,
	CST816_LpScanIdac,
	CST816_AutoSleepTime,
	CST816_IrqCtl,
	CST816_AutoReset,
	CST816_LongPressTime,
	CST816_IOCtl,
	CST816_DisAutoSleep
} CST816S_Register;

struct cst816s_i2c {
	struct i2c_client *client;
	struct input_dev *input;
	u8 data[CST816S_QUERY_SIZE];
	//bool prox;
	//int tool;
};

struct cst816s_chip_info {
	//bool	have_z;
	u16	max_x;
	u16	max_y;
	//u16	max_area;
	//u16	max_fingers;
	//u8	start_reg;
};

static const struct cst816s_chip_info _cst816s_chip_info = {
	//.have_z		= true,
	.max_x		= 0xf0, /* 240 - 1 */
	.max_y		= 0xf0, /* 240 - 1 */
};

static irqreturn_t cst816s_i2c_irq(int irq, void *dev_id)
{
	struct cst816s_i2c *lcst816s_i2c = dev_id;
	struct input_dev *input = lcst816s_i2c->input;
	u8 *data = lcst816s_i2c->data;
	unsigned int x, y, button, gestureID;
	int ret;
	
	//printk("--------> ildusv: cst816s_i2c_irq called\n");
	data[0] = CST816_GestureID;
	data[1] = 0x00;
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x00;

	// First, write the register address to the device
	ret = i2c_master_send(lcst816s_i2c->client, data, 1);
	if (ret < 0) {
		printk("Failed to write register address to I2C device\n");
		goto out;
	}

	// Now, read the data from the device
	ret = i2c_master_recv(lcst816s_i2c->client, data, 6);
	if (ret < 0) {
		printk("Failed to read data from I2C device\n");
		goto out;
	}

	gestureID = data[0];
	button = data[2] >> 6;
	x = ((data[2] & 0x0f) << 8) + data[3];
	y = ((data[4] & 0x0f) << 8) + data[5];

	// printk("--------> ildusv: x:%d y:%d button:%x gestureID:%x gesture:%s\n", x, y, button, gestureID, gesture(gestureID));

	input_report_abs(input, ABS_X, x);
	input_report_abs(input, ABS_Y, y);
	input_report_key(input, BTN_TOUCH, (button > 1) ? 1 : 0);
	input_sync(input);

out:
	return IRQ_HANDLED;
}

static int cst816s_i2c_open(struct input_dev *dev)
{
	struct cst816s_i2c *lcst816s_i2c = input_get_drvdata(dev);
	struct i2c_client *client = lcst816s_i2c->client;

	//dev_dbg(&client->dev, "ildusv: cst816s open() driver...\n");
	printk("--------> ildusv: cst816s open() driver...\n");
	enable_irq(client->irq);

	return 0;
}

static void cst816s_i2c_close(struct input_dev *dev)
{
	struct cst816s_i2c *lcst816s_i2c = input_get_drvdata(dev);
	struct i2c_client *client = lcst816s_i2c->client;

	//dev_dbg(&client->dev, "--------> ildusv: cst816s close() driver...\n");
	printk("--------> ildusv: cst816s close() driver...\n");
	//ildusv:temporarily disable, since kernel closes it for some reason
	disable_irq(client->irq);
}

static int cst816s_i2c_probe(struct i2c_client *client,
				     const struct i2c_device_id *id)
{
	struct cst816s_i2c *lcst816s_i2c;
	struct input_dev *input;
	int error;

	printk("--------> ildusv: cst816s probing...\n");

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c_check_functionality error\n");
		return -EIO;
	}

	lcst816s_i2c = kzalloc(sizeof(*lcst816s_i2c), GFP_KERNEL);
	input = input_allocate_device();
	if (!lcst816s_i2c || !input) {
		dev_err(&client->dev, "--------> ildusv: input_allocate_device() error\n");
		printk("--------> ildusv: input_allocate_device() error\n");
		error = -ENOMEM;
		goto err_free_mem;
	}

	lcst816s_i2c->client = client;
	lcst816s_i2c->input = input;

	input->name = CST816S_NAME;
	input->id.bustype = BUS_I2C;

	input->id.vendor = 0x56a;
	input->id.version = 1;
	input->dev.parent = &client->dev;
	input->open = cst816s_i2c_open;
	input->close = cst816s_i2c_close;

    // Set the event types - only EV_ABS for absolute position reporting
	input->evbit[0] |= BIT_MASK(EV_ABS);

	__set_bit(INPUT_PROP_DIRECT, input->propbit);
	input_set_capability(input, EV_KEY, BTN_TOUCH);
	input_set_abs_params(input, ABS_X, 0, 240, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, 240, 0, 0);
	
	input_set_drvdata(input, lcst816s_i2c);

	error = request_threaded_irq(client->irq, NULL, cst816s_i2c_irq,
				     IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				     CST816S_NAME, lcst816s_i2c);
	
	if (error) {
		dev_err(&client->dev,
			"Failed to enable IRQ, error: %d\n", error);
		printk("--------> ildusv: Failed to enable IRQ, error: %d\n", error);
		goto err_free_mem;
	}

	/* Disable the IRQ, we'll enable it in wac_i2c_open() */
	disable_irq(client->irq);

	error = input_register_device(lcst816s_i2c->input);
	if (error) {
		dev_err(&client->dev,
			"Failed to register input device, error: %d\n", error);
		printk("--------> ildusv: Failed to register input device, error: %d\n", error);
		goto err_free_irq;
	}

	i2c_set_clientdata(client, lcst816s_i2c);
	printk("--------> ildusv: Probing exited OK\n");
	return 0;

err_free_irq:
	free_irq(client->irq, lcst816s_i2c);
err_free_mem:
	input_free_device(input);
	kfree(lcst816s_i2c);

	return error;
}

static int cst816s_i2c_remove(struct i2c_client *client)
{
	struct cst816s_i2c *lcst816s_i2c = i2c_get_clientdata(client);
	printk("--------> ildusv: cst816s remove()\n");
	free_irq(client->irq, lcst816s_i2c);
	input_unregister_device(lcst816s_i2c->input);
	kfree(lcst816s_i2c);

	return 0;
}

static int __maybe_unused cst816s_i2c_suspend(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	printk("--------> ildusv: cst816s suspend()\n");
	disable_irq(client->irq);

	return 0;
}

static int __maybe_unused cst816s_i2c_resume(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	printk("--------> ildusv: cst816s resume()\n");
	enable_irq(client->irq);

	return 0;
}

static SIMPLE_DEV_PM_OPS(cst816s_i2c_pm, cst816s_i2c_suspend, cst816s_i2c_resume);


//ildusv: need to change the ID
static const struct i2c_device_id cst816s_i2c_id[] = {
	{ CST816S_NAME, 0 },
	{ },
};
MODULE_DEVICE_TABLE(i2c, cst816s_i2c_id);

static const struct of_device_id cst816s_ts_dt_ids[] = {
	{ .compatible = "hynix,cst816s", .data = &_cst816s_chip_info },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, cst816s_ts_dt_ids);

static struct i2c_driver cst816s_i2c_driver = {
	.driver	= {
		.name = CST816S_NAME,
		.of_match_table = cst816s_ts_dt_ids,
		.pm	= &cst816s_i2c_pm
	},
	.probe		= cst816s_i2c_probe,
	.remove		= cst816s_i2c_remove,
	.id_table	= cst816s_i2c_id,
};

module_i2c_driver(cst816s_i2c_driver);

MODULE_AUTHOR("Ildus Valiev <ildus.rafkatovich@gmail.com>");
MODULE_DESCRIPTION("CST816S I2C Driver");
MODULE_LICENSE("GPL");