from influxdb_client import InfluxDBClient, Point
from influxdb_client.client.write_api import SYNCHRONOUS

from time import sleep
import iio

ctx = iio.LocalContext()
ctrl = ctx.find_device('tsl2591')

chan = ctrl.find_channel('illuminance')
bucket = "ch12"

client = InfluxDBClient(url="http://localhost:8086", token="3563QrhOmUNToC_zA_ALsfqaN9LlBFk9B2r3nqSTtZoa32PdfB1xz7_SbQu5vLsH7AxJAfj4QXVYsmIKMnP2EQ==", org="packt")
write_api = client.write_api(write_options=SYNCHRONOUS)

while True:
    intensity = chan.attrs['input'].value
    p = Point("measurement").tag("location", "office").field("intensity", intensity)
    write_api.write(bucket=bucket, record=p)
    sleep(0.1)
