#!/bin/bash
rm -rf leetcode/*
cp ./bak/* leetcode/
rm SUMMARY.md
cp SUMMARY_bak.md SUMMARY.md
./hexotogitbook.sh
