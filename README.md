# Vibration Sensor by `David Abeziz`

The objective of this payload is to measure the vibration frequencies and amplitudes of the flight. To measure vibrations, we are using a piezoelectric material, as these are low cost and used in many applications.

## Images and Explanations

### Figure 27 and 28
![Figure 27 and 28](Images/Screenshot%20from%202024-07-16%2014-26-39.png) <br>
These figures show the results of a vibration table test conducted with multiple frequencies (Figure 27) and a single note test at 330Hz (Figure 28). Both tests were sampled at 2000Hz.

### Figure 29 and 30
![Figure 29 and 30](Images/Screenshot%20from%202024-07-16%2014-27-29.png) <br>
These figures represent a short interval test (Figure 29) and a single note test at 330Hz (Figure 30) with a sampling rate of 4000Hz, demonstrating the captured vibration signals and their analysis.

### Figure 31
![Figure 31](Images/Screenshot%20from%202024-07-16%2014-28-08.png) <br>
This figure displays the payload assembly, showcasing the integration of the piezoelectric sensor and other electronic components within the housing.

---

## Concept Revision

Many devices that use piezoelectric materials, such as electric violins, take vibrations from the instrument and recreate the signals digitally. This property can be applied to rockets as well. After considering the previous payload design, we determined that using a piezoelectric disk to measure vibration amplitudes and frequencies would be more efficient.

We needed a microcontroller and an SD chip to log the flight data. For this, we used a Teensy 4.0 due to its fast performance and small size, making it optimal for working with vibration data. To avoid the chance of memory loss due to an SD card coming loose, we used an SPI 512 to log data. To avoid file overload, a new file is created when the SPI is powered on.

## Testing and Data Analysis

MATLAB is a powerful tool often used in data analysis applications. One such app, “Signal Analyser,” was used to analyze the data in both the time and frequency domains. Most rockets have large vibrations but relatively low amplitudes, so an FFT analysis needed a range of no more than 1000 Hz to record the expected frequencies.

The range of frequencies by an FFT is related to the sampling frequency through the equation \( F_s = 2F_n \), where \( F_n \) is the Nyquist Frequency, and \( F_s \) is the sampling frequency. To achieve a maximum range of frequencies to be 1000 Hz, we sampled at 2000 Hz or every 500 microseconds.

## Results

Figure 28 shows the signal from the string of a Ukulele vibrating at 330 Hz using a sampling frequency of 2000 Hz. The acoustic nature of the instrument accounts for the various peaks shown. Figure 27 shows a section of the signal from the oscillations of the vibration table at York University. The table gradually increased its oscillated frequency from 10 to 100 Hz, resulting in the bar of frequencies seen in the Power vs Frequency plot for the selected range.

These results indicate that the Piezo sensor can accurately record frequencies in a controlled environment. However, in the uncontrolled environment of a rocket, there may be quick changes between frequencies. Increasing the sample rate means we can view higher frequencies if needed and increase the accuracy of the FFT, capturing shorter-lived oscillations during the launch.

Figure 30 again shows the signal from the string of a Ukulele vibrating at 330 Hz using a sampling frequency of 4000 Hz. The acoustic nature of the instrument accounts for the peaks shown at 330 Hz and one octave above (660Hz). Figure 29 shows a section of the signal from the strings of a Ukulele vibrating up in semitones from 330 Hz to 880 Hz. Each note vibrates for shorter intervals, but the sensor at 4000 Hz still accurately picks up the frequencies.

A common error observed is the momentary absence of a received signal from the sensor, seen as a line bridging two ends of a signal not recorded. Although this may decrease the accuracy slightly, MATLAB’s built-in signal panner allows for close inspection, rendering the effects almost invisible. The cause of this missing data is still being investigated, likely due to the Teensy 4.0’s ability to analyze incoming data.

## Payload Housing

The payload will be located in the nosecone of the rocket within a 3D printed housing. The payload assembly includes:
1. Teensy 4.0
2. SPI SMT 512M SD
3. Prototyping Board
4. Piezoelectric Disk
5. 2 Lipo Batteries
6. 5V Regulator
7. Housing
8. Housing Cap

The Housing Cap ensures the payload will not slide around during launch, maintaining sensor accuracy.
