import serial
import time

ser = serial.Serial('COM4', 500000)  # 4pdate COM4 to your Arduino's port
output_file = "C:/Users/david/OneDrive/Documents/Arduino/FlighData/ViolinTest2.txt"

start_time = time.time()  # Record the start time
duration = 40  # Set the desired duration in seconds

with open(output_file, 'w') as file:
    while time.time() - start_time < duration:
        if ser.inWaiting() > 0:
            line = ser.readline().decode('utf-8').rstrip()
            file.write(line + '\n')

# The loop will exit after the specified duration
