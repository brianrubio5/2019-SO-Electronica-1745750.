




api_key=SQ6WO59ME980M8OR



programapthn=`/usr/bin/python /home/root/sensor_temperatura.py`


datotemp=`echo $programapthn | awk '{print $1}'`



curl --data "api_key=$api_key&field1=$datotemp&field2=$(date)" https://api.thingspeak.com/update





