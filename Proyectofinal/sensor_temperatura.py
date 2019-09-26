import mraa 
import time

pin_analog = 1


t = mraa.Aio(pin_analog)




temp = t.read()
finaltmp=(5.0 * temp * 100.0)/1024.0


print(finaltmp)


