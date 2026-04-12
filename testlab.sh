#!/bin/bash

# OPS102 Bonus Lab - Software Testing Script
# - IPC144 Lab 6 source files used for testing
# - GenAI used: ChatGPT
# - Prompt used:
#   Help me with guidance for building and understanding how to create a Bash script to test my C program using input and expected output files.

PROGRAM="program"
PASS_COUNT=0
TOTAL_TESTS=4

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "========================================"
echo "     IPC144 Currency Tester"
echo "========================================"
echo

echo -e "${BLUE}Compiling source files...${NC}"
gcc -Wall lab6.c lab6main.c -o "$PROGRAM"

if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful.${NC}"
echo

run_test() {
    TEST_NUM=$1
    INPUT_FILE=$2
    EXPECTED_FILE=$3
    OUTPUT_FILE="output${TEST_NUM}"

    echo -e "${BLUE}Running Test $TEST_NUM...${NC}"

    if [ ! -f "$INPUT_FILE" ]; then
        echo -e "${RED}Missing input file: $INPUT_FILE${NC}"
        echo "----------------------------------------"
        return
    fi

    if [ ! -f "$EXPECTED_FILE" ]; then
        echo -e "${RED}Missing expected file: $EXPECTED_FILE${NC}"
        echo "----------------------------------------"
        return
    fi

    ./"$PROGRAM" < "$INPUT_FILE" > "$OUTPUT_FILE"

    if diff -q "$OUTPUT_FILE" "$EXPECTED_FILE" > /dev/null; then
        echo -e "${GREEN}Test $TEST_NUM: PASS${NC}"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo -e "${RED}Test $TEST_NUM: FAIL${NC}"
        echo -e "${YELLOW}Expected output:${NC}"
        cat "$EXPECTED_FILE"
        echo
        echo -e "${YELLOW}Actual output:${NC}"
        cat "$OUTPUT_FILE"
        echo
    fi

    echo "----------------------------------------"
}

run_test 1 input1 expected1
run_test 2 input2 expected2
run_test 3 input3 expected3
run_test 4 input4 expected4

echo
echo "Finished testing."
echo "Passed $PASS_COUNT out of $TOTAL_TESTS tests."

if [ "$PASS_COUNT" -eq "$TOTAL_TESTS" ]; then
    echo -e "${GREEN}All tests passed.${NC}"
else
    echo -e "${RED}Some tests failed.${NC}"
fi
