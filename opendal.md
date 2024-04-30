
# people 

xuanwo


# inbox

maturin develop

maturin develop -E test
# To run `test_write.py` and use `fs` operator
OPENDAL_TEST=fs OPENDAL_FS_ROOT=/tmp pytest -vk test_write


python -m venv venv
source venv/bin/activate
pip install maturin[patchelf]

test_sync_reader
maturin 
maturin develop -E test

OPENDAL_TEST=fs OPENDAL_FS_ROOT=/tmp pytest -vk test_read

# dev

