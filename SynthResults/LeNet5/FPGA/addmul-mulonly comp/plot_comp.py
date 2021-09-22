import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate
from matplotlib.lines import Line2D

def plot_hw_resources(csv_file_1, label_1, csv_file_2, label_2, fpga_pdf):
    error_1    = np.genfromtxt(csv_file_1, delimiter=';', usecols=(1), skip_header=1)
    luts_conv1 = np.genfromtxt(csv_file_1, delimiter=';', usecols=(3), skip_header=1) / 1000
    luts_conv2 = np.genfromtxt(csv_file_1, delimiter=';', usecols=(4), skip_header=1) / 1000
    luts_conv3 = np.genfromtxt(csv_file_1, delimiter=';', usecols=(5), skip_header=1) / 1000
    luts_fc1   = np.genfromtxt(csv_file_1, delimiter=';', usecols=(6), skip_header=1) / 1000
    luts_fc2   = np.genfromtxt(csv_file_1, delimiter=';', usecols=(7), skip_header=1) / 1000
    resources_1 = luts_conv1 + luts_conv2 + luts_conv3 + luts_fc1 + luts_fc2;

    error_2    = np.genfromtxt(csv_file_2, delimiter=';', usecols=(1), skip_header=1)
    luts_conv1 = np.genfromtxt(csv_file_2, delimiter=';', usecols=(3), skip_header=1) / 1000
    luts_conv2 = np.genfromtxt(csv_file_2, delimiter=';', usecols=(4), skip_header=1) / 1000
    luts_conv3 = np.genfromtxt(csv_file_2, delimiter=';', usecols=(5), skip_header=1) / 1000
    luts_fc1   = np.genfromtxt(csv_file_2, delimiter=';', usecols=(6), skip_header=1) / 1000
    luts_fc2   = np.genfromtxt(csv_file_2, delimiter=';', usecols=(7), skip_header=1) / 1000
    resources_2 = luts_conv1 + luts_conv2 + luts_conv3 + luts_fc1 + luts_fc2;

    plt.figure(figsize=[6, 3])
    plt.plot(error_1, resources_1, 'r.', label=label_1)
    plt.plot(error_2, resources_2, 'b.', label=label_2)
    plt.ylabel('Required LUTs (in thousands)')
    plt.xlabel('Accuracy loss (%)')
    plt.legend(frameon=False, loc='upper center', ncol=2, bbox_to_anchor=(0.2, 0.62, 0.5, 0.5))
    plt.savefig(fpga_pdf, bbox_inches='tight', pad_inches=0)
    
def plot_power(csv_file_1, label_1, csv_file_2, label_2, plot_pdf):
    error_1   = np.genfromtxt(csv_file_1, delimiter=';', usecols=(1), skip_header=1)
    pwr_conv1 = np.genfromtxt(csv_file_1, delimiter=';', usecols=(17), skip_header=1) / 1000
    pwr_conv2 = np.genfromtxt(csv_file_1, delimiter=';', usecols=(18), skip_header=1) / 1000
    pwr_conv3 = np.genfromtxt(csv_file_1, delimiter=';', usecols=(19), skip_header=1) / 1000
    pwr_fc1   = np.genfromtxt(csv_file_1, delimiter=';', usecols=(20), skip_header=1) / 1000
    pwr_fc2   = np.genfromtxt(csv_file_1, delimiter=';', usecols=(21), skip_header=1) / 1000
    power_1 = pwr_conv1 + pwr_conv2 + pwr_conv3 + pwr_fc1 + pwr_fc2

    error_2   = np.genfromtxt(csv_file_2, delimiter=';', usecols=(1), skip_header=1)
    pwr_conv1 = np.genfromtxt(csv_file_2, delimiter=';', usecols=(17), skip_header=1) / 1000
    pwr_conv2 = np.genfromtxt(csv_file_2, delimiter=';', usecols=(18), skip_header=1) / 1000
    pwr_conv3 = np.genfromtxt(csv_file_2, delimiter=';', usecols=(19), skip_header=1) / 1000
    pwr_fc1   = np.genfromtxt(csv_file_2, delimiter=';', usecols=(20), skip_header=1) / 1000
    pwr_fc2   = np.genfromtxt(csv_file_2, delimiter=';', usecols=(21), skip_header=1) / 1000
    power_2 = pwr_conv1 + pwr_conv2 + pwr_conv3 + pwr_fc1 + pwr_fc2

    plt.figure(figsize=[6, 3])
    plt.plot(error_1, power_1, 'r.', label=label_1)
    plt.plot(error_2, power_2, 'b.', label=label_2)
    plt.ylabel('Power consumption (mW)')
    plt.xlabel('Accuracy loss (%)')
    plt.legend(frameon=False, loc='upper center', ncol=2, bbox_to_anchor=(0.2, 0.62, 0.5, 0.5))
    plt.savefig(plot_pdf, bbox_inches='tight', pad_inches=0)

plot_hw_resources('addMul.csv', 'Add & Mul', 'mulOnly.csv', 'Mul only', 'lenet5_8bits_addmul_mulonly_comp_luts.pdf')
plot_power('addMul.csv', 'Add & Mul', 'mulOnly.csv', 'Mul only', 'lenet5_8bits_addmul_mulonly_comp_power.pdf')
