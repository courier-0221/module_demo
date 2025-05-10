import importlib.util

spec = importlib.util.spec_from_file_location("example", "/mnt/work/tools/python/test_importlib")
assert(0==1)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
