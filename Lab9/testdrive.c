#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>

static struct of_device_id testdev_ids[] = {
	{ .compatible = "test,mydevice" },
	{ .compatible = "test,mytestdevice"},
	{ /* sentinel */},
};
MODULE_DEVICE_TABLE(of, testdev_ids);

static int testdev_probe(struct platform_device *drv){
	const char *mystring = NULL;
	int u32val = 0;
	struct device_node *np = drv->dev.of_node;

	printk("Hello from platform device %s!\n", drv->name);
	
	of_property_read_string(np, "string-property", &mystring);
	printk("string from dtb: %s\n", mystring);

	of_property_read_u32(np, "number-property", &u32val);
	printk("string from dtb: %s\n", u32val);
	
	return 0;
}

static int testdev_remove(struct platform_device *drv){
	printk("my device removed\n");
	return 0;
}

static struct platform_driver pdrv = {
	.probe = testdev_probe,
	.remove = testdev_remove,
	.driver = {
		.name = "testdevdrv",
		.of_match_table = of_match_ptr(testdev_ids),
		.owner = THIS_MODULE,
	},
};

module_platform_driver(pdrv);

MODULE_AUTHOR("Doulos Ltd");
MODULE_DESCRIPTION("Example");
MODULE_LICENSE("GPL");
MODULE_vERSION("0.1");















