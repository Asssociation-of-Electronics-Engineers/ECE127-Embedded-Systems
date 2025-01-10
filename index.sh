#!/bin/bash

# Function to display help menu
cmd_help() {
    echo "Available commands:"
    echo "  help        - List all commands"
    echo "  led <on|off> - Control LED (on/off)"
    echo "  info        - Display system information"
}

# Function to control the LED
cmd_led() {
    if [[ $1 == "on" ]]; then
        echo "Turning LED ON"
        # Simulate LED ON behavior here
    elif [[ $1 == "off" ]]; then
        echo "Turning LED OFF"
        # Simulate LED OFF behavior here
    else
        echo "Usage: led <on|off>"
    fi
}

# Function to display system information
cmd_info() {
    echo "System Information:"
    echo "  CPU: Embedded Cortex-M4"
    echo "  Firmware Version: 1.0.0"
    echo "  Uptime: $(uptime -p)"
}

# Main shell loop
echo "Embedded System Shell. Type 'help' for commands."
while true; do
    echo -n "> "
    read -r command args

    case $command in
        help)
            cmd_help
            ;;
        led)
            cmd_led $args
            ;;
        info)
            cmd_info
            ;;
        exit)
            echo "Exiting shell..."
            break
            ;;
        *)
            echo "Unknown command: $command"
            ;;
    esac
done
