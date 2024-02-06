#!/bin/bash

# Get the current directory of the script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Step 1: List Bluetooth devices
echo "Step 1: Listing Bluetooth devices..."
hcitool dev

# Step 2: Save the PC MAC address
read -p "Step 2: Enter the MAC address of your PC (xx:xx:xx:xx:xx:xx): " PC_DEVICE

# Step 3: List Bluetooth devices again and prompt for the correct one
echo "Step 3: Listing Bluetooth devices again..."
bluetoothctl devices

# Prompt the user to copy the correct MAC address
read -p "Step 3: Enter the MAC address of the NOVA glove (copy from the list): " SG_DEVICE

# Step 5: Connect to the NOVA glove
echo "Step 5: Connecting to the NOVA glove..."
SG_RFCOMM="/dev/rfcomm0"
sudo bluetoothctl pairable on
sudo bluetoothctl discoverable on
sudo bluetoothctl pair "$SG_DEVICE"
sudo bluetoothctl trust "$SG_DEVICE"
sudo bluetoothctl connect "$SG_DEVICE"
sudo rfcomm connect "$SG_RFCOMM" "$SG_DEVICE" 1 &

# Step 6: Navigating to SenseCom directory
echo "Step 6: Navigating to SenseCom directory..."
cd "$SCRIPT_DIR/../external/SenseCom" || { echo "Directory not found. Please check the path."; exit 1; }

# Check if SenseCom_Linux directory exists
if [ ! -d "SenseCom_Linux" ]; then
  # Step 7: Extracting SenseCom_Linux
  echo "Step 7: Extracting SenseCom_Linux..."
  unzip -o SenseCom_Linux.zip || { echo "Failed to extract SenseCom_Linux.zip. Make sure the file is in the correct location."; exit 1; }
fi

# Step 10: Running SenseCom.x86_64
echo "Step 10: Running SenseCom.x86_64..."
cd "SenseCom_Linux/SenseCom" || { echo "Directory not found. Please check the path."; exit 1; }
chmod +x SenseCom.x86_64  # Give execute permission
./SenseCom.x86_64 || { echo "Failed to run SenseCom.x86_64."; exit 1; }

echo "Script completed."

