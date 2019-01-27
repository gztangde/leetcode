#!/bin/bash
rm -rf leetcode/*
cp ./leet_bak/* leetcode/
rm SUMMARY.md
cp SUMMARY_BAK.md SUMMARY.md
./hexotogitbook.sh
