# SenseGlove-Robotics

## Overview

SenseGlove-Robotics is a project designed to enable to connect the NOVA glove and use it to control a robotic arm. This script has been developed and tested specifically for use with SenseGlove Nova 1.

## Prerequisites

This was developed with:

- Ubuntu 22.04
- SenseGlove Nova 1

## Connect the glove

1. **Navigate to the `scripts` folder where the `glove_connect.sh` script is located:**

    ```bash
    cd scripts
    ```

2. **Make the script executable:**

    ```bash
    chmod +x glove_connect.sh
    ```

3. **Run the script with sudo:**

    ```bash
    sudo ./glove_connect.sh
    ```

    The script will perform the following steps:
        List Bluetooth devices and prompt you to enter the MAC address of your PC.
        List Bluetooth devices again and prompt you to copy the MAC address of the NOVA glove from the list.
        Connect to the NOVA glove.
        Check if the SenseCom_Linux directory exists and extract it from ZIP if necessary.
        Run the SenseCom.x86_64 executable.

    If the glove LED turns solid blue, the SenseCom window will appear. Keep this window open, perform glove calibration, and wait for the glove to connect.

    If the glove LED doesn't turn solid blue, exit the script, and try running it again. If the issue persists, you may need to debug your Bluetooth locally.

Note: Ensure that you have the necessary permissions to execute the script with sudo.

**Troubleshooting**

If you encounter any issues during the connection process, consider the following troubleshooting steps:

    Ensure your NOVA glove is charged and powered on.
    Verify that Bluetooth is enabled on your computer.
    Confirm that the NOVA glove is in pairing mode.
    Check that the SenseCom.x86_64 executable is in the correct location.

**Additional Resources**

For more information, user manuals, or support, please visit our SenseGlove-Robotics Documentation or contact our Support Team.

**License**

This project is licensed under the MIT License.