from time import sleep
import iio

ctx = iio.LocalContext()
ctrl = ctx.find_device('tsl2591')

chan = ctrl.find_channel('illuminance')

while True:
    intensity = chan.attrs['input'].value
    print(intensity)
    sleep(0.1)
