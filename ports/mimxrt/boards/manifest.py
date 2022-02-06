freeze("$(PORT_DIR)/modules")
freeze("$(MPY_DIR)/drivers/onewire")
freeze("$(MPY_DIR)/drivers/dht", "dht.py")
include("$(MPY_DIR)/extmod/uasyncio/manifest.py")
try:
    include("$(BOARD_DIR)/manifest.py")
except FileNotFoundError:
    pass
