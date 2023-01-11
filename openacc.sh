#!/bin/bash
#SBATCH --nodes=1
#SBATCH --job-name=a.out
#SBATCH --time=12:30:00
#SBATCH --gres=gpu:1
#SBATCH --output=%j.out
#SBATCH --error=%j.err
export PGI_ACC_NOTIFY=5
nsys profile a.out
