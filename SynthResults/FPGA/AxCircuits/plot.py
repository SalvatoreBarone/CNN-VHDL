import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate
from matplotlib.lines import Line2D

def plot_pareto(front_csv_file, pareto_csv_file, final_plot_pdf):
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    ax.set_xlabel('Error (%)')
    ax.set_ylabel('Silicon Area (um²)')
    ax.set_zlabel('Power Consumption (mW)')

    error = np.genfromtxt(front_csv_file, delimiter=',', usecols=(0), skip_header=1)
    area =  np.genfromtxt(front_csv_file, delimiter=',', usecols=(1), skip_header=1)
    power = np.genfromtxt(front_csv_file, delimiter=',', usecols=(2), skip_header=1)
    ax.scatter(error, area, power, marker='.')

    error = np.genfromtxt(pareto_csv_file, delimiter=',', usecols=(0), skip_header=1)
    area =  np.genfromtxt(pareto_csv_file, delimiter=',', usecols=(1), skip_header=1)
    power = np.genfromtxt(pareto_csv_file, delimiter=',', usecols=(2), skip_header=1)
    ax.scatter(error, area, power, marker = 'o')

    plt.legend(frameon=False, loc='upper center', ncol=2)
    plt.tight_layout()
    plt.savefig(final_plot_pdf, bbox_inches='tight', pad_inches=0)


plot_pareto('FinalPopulation.csv', 'Front.csv', 'lenet5_axcirc_dse_result.pdf')
