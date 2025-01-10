#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 50
#define MAX_ARGUMENTS 5

typedef void (*CommandFunction)(int argc, char *argv[]);

void cmd_help(int argc, char *argv[]);
void cmd_led(int argc, char *argv[]);
void cmd_info(int argc, char *argv[]);

typedef struct {
    const char *command;
    CommandFunction function;
    const char *description;
} ShellCommand;

ShellCommand commands[] = {
    {"help", cmd_help, "List all commands"},
    {"led", cmd_led, "Control LED (on/off)"},
    {"info", cmd_info, "Display system information"},
    {NULL, NULL, NULL}
};

void cmd_help(int argc, char *argv[]) {
    for (int i = 0; commands[i].command != NULL; i++) {
        printf("  %s - %s\n", commands[i].command, commands[i].description);
    }
}

void cmd_led(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: led <on|off>\n");
        return;
    }
    if (strcmp(argv[1], "on") == 0) {
        printf("Turning LED ON\n");
    } else if (strcmp(argv[1], "off") == 0) {
        printf("Turning LED OFF\n");
    } else {
        printf("Invalid argument: %s\n", argv[1]);
    }
}

void cmd_info(int argc, char *argv[]) {
    printf("System Information:\n");
    printf("  CPU: Embedded Cortex-M4\n");
    printf("  Firmware Version: 1.0.0\n");
    printf("  Uptime: 1200 seconds\n");
}

void shell_execute(char *input) {
    char *argv[MAX_ARGUMENTS];
    int argc = 0;
    char *token = strtok(input, " ");
    while (token != NULL && argc < MAX_ARGUMENTS) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    if (argc == 0) return;
    for (int i = 0; commands[i].command != NULL; i++) {
        if (strcmp(argv[0], commands[i].command) == 0) {
            commands[i].function(argc, argv);
            return;
        }
    }
    printf("Unknown command: %s\n", argv[0]);
}

void shell_start() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) break;
        input[strcspn(input, "\n")] = '\0';
        shell_execute(input);
    }
}
