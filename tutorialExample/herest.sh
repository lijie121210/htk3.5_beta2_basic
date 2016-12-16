#!/bin/bash

HERest -C ./config/config2 -I phones0.mlf -t 250.0 150.0 1000.0 \
-S train.scp -H ./hmm0/Macros -H ./hmm0/hmmdefs -M ./hmm1 monophones2
