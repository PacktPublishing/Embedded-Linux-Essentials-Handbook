import time
import spidev

spi_ch = 0

# Enable SPI
spi = spidev.SpiDev(0, spi_ch)
spi.max_speed_hz = 1200000

reply = spi.xfer([208, 0]) # 0xD0 to retrieve chip_id

print("chip_id: ", reply)
