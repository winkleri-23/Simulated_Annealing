

import os
import subprocess


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


def N_Data(directory, package, CoolingFactor):
    for filename in sorted(os.listdir(directory)):
        f = os.path.join(directory, filename)
        # checking if it is a file
        if os.path.isfile(f):
            s = subprocess.getstatusoutput(
                './../Derived_data/KOP-gvejrnjqxssflrdgkwcnbgcoffuv/Build/Products/Debug/KOP ' + f + ' ../Measurements/' + package + '/ ' + package+ ' ' + str(CoolingFactor))
            if s[0] == 0:
                print(s[1])

            print(f)

def Q_Data(directory,package, CoolingFactor):
    for filename in sorted(os.listdir(directory)):
        f = os.path.join(directory, filename)
        # checking if it is a file
        if os.path.isfile(f):
            s = subprocess.getstatusoutput(
                './../Derived_data/KOP-gvejrnjqxssflrdgkwcnbgcoffuv/Build/Products/Debug/KOP ' + f + ' ../Measurements/' + package + '/ ' + package+ ' ' + str(CoolingFactor))
            if s[0] == 0:
                print(s[1])

            print(f)

def R_Data(directory,package, CoolingFactor ):
    for filename in sorted(os.listdir(directory)):
        f = os.path.join(directory, filename)
        # checking if it is a file
        if os.path.isfile(f):
            s = subprocess.getstatusoutput(
                './../Derived_data/KOP-gvejrnjqxssflrdgkwcnbgcoffuv/Build/Products/Debug/KOP ' + f + ' ../Measurements/' + package + '/ ' + package+ ' ' + str(CoolingFactor))
            if s[0] == 0:
                print(s[1])

            print(f)



def M_Data(directory, package,CoolingFactor):
    for filename in sorted(os.listdir(directory)):
        f = os.path.join(directory, filename)
        # checking if it is a file
        if os.path.isfile(f):
            s = subprocess.getstatusoutput(
                './../Derived_data/KOP-gvejrnjqxssflrdgkwcnbgcoffuv/Build/Products/Debug/KOP ' + f + ' ../Measurements-final/' + package + '/ ' + package + ' ' + str(CoolingFactor))
            if s[0] == 0:
                print(s[1])

            print(f)

def M_Data_50(directory, package, CoolingFactor):
    for filename in sorted(os.listdir(directory)):
        f = os.path.join(directory, filename)
        # checking if it is a file
        if os.path.isfile(f):
            print("a")
            s = subprocess.getstatusoutput(
                './../Derived_data/KOP-gvejrnjqxssflrdgkwcnbgcoffuv/Build/Products/Debug/KOP ' + f + ' ../Measurements-final/' + package + '/ ' + package+ ' ' + str(CoolingFactor))
            if s[0] == 0:
                print(s[1])

            print(f)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    #M_Data('../../../wuf20-91/wuf20-91-M', 'M', 0.95)
    #M_Data('../../../wuf20-91/wuf20-91-N', 'N', 0.95)
    #M_Data('../../../wuf20-91/wuf20-91-R', 'R', 0.95)
    #M_Data('../../../wuf20-91/wuf20-91-Q', 'Q', 0.95)

    #M_Data_50('../../../wuf50-218/wuf50-218-M', 'M', 0.95)
    #M_Data_50('../../../wuf50-218/wuf50-218-N', 'N', 0.95)
    #M_Data_50('../../../wuf50-218/wuf50-218-R', 'R', 0.95)
    #M_Data_50('../../../wuf50-218/wuf50-218-Q', 'Q', 0.95)


    #M_Data_50('../../../wuf75-325/wuf75-325-M', 'M', 0.95)
    #M_Data_50('../../../wuf75-325/wuf75-325-N', 'N', 0.95)
    #M_Data_50('../../../wuf75-325/wuf75-325-R', 'R', 0.95)
    #M_Data_50('../../../wuf75-325/wuf75-325-Q', 'Q', 0.95)


    #M_Data('../../../wuf20-91R/wuf20-91R-M', 'M', 0.99)
    #M_Data('../../../wuf20-91R/wuf20-91R-M', 'M', 0.95)
    #M_Data('../../../wuf20-91R/wuf20-91R-M', 'M', 0.99)
    #M_Data('../../../wuf20-91R/wuf20-91R-M', 'M', 0.95)
    #M_Data('../../../wuf20-91R/wuf20-91R-N', 'N', 0.95)
    #M_Data('../../../wuf20-91R/wuf20-91R-Q', 'Q', 0.95)
    #M_Data('../../../wuf20-91R/wuf20-91R-R', 'R', 0.95)

    M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.90)
    #M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.92)
    #M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.92)

    #M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.92)
    #M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.9)
    #M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.99)
    #M_Data_50('../../../wuf50-218R/wuf50-218R-M', 'M', 0.99)
    #M_Data_50('../../../wuf50-218/wuf50-218-N', 'N', 0.9)
    #M_Data_50('../../../wuf50-218/wuf50-218-Q', 'Q', 0.95)
    #M_Data_50('../../../wuf50-218/wuf50-218-R', 'R', 0.95)

    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
