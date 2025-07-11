#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
LS_CMD="$SCRIPT_DIR/../ft_ls"
TEST_DIR=test_dir

# create a test directory and files
if [ -d "$TEST_DIR" ]; then
    rm -rf "$TEST_DIR"
fi

mkdir "$TEST_DIR"
touch "test_dir/file1.txt"
touch "test_dir/file2.txt"
touch "test_dir/file3.txt"

LS_OUTPUT=$(ls test_dir)

TEST_OUTPUT=$($LS_CMD test_dir)

if [ "$LS_OUTPUT" = "$TEST_OUTPUT" ]; then
    echo "Smoke test passed: ft_ls output matches standard ls output."
else
    echo "Smoke test failed: ft_ls output does not match standard ls output."
    echo "Expected:"
    echo "$LS_OUTPUT"
    echo "Got:"
    echo "$TEST_OUTPUT"
    exit 1
fi

LS_OUTPUT=$(ls -l test_dir)
TEST_OUTPUT=$($LS_CMD -l test_dir)

if [ "$LS_OUTPUT" = "$TEST_OUTPUT" ]; then
    echo "Smoke test passed: ft_ls -l output matches standard ls -l output."
else
    echo "Smoke test failed: ft_ls -l output does not match standard ls -l output."
    echo "Expected:"
    echo "$LS_OUTPUT"
    echo "Got:"
    echo "$TEST_OUTPUT"
    exit 1
fi

# Clean up test directory
rm -rf "$TEST_DIR"
echo "All smoke tests passed successfully."
exit 0