# -*- coding: utf-8 -*-
"""
Created on Sun Jul 22 18:05:14 2018

@author: tima
"""

import numpy as np
import matplotlib.pyplot as plt
import sys
import os
from PyPDF2 import PdfFileMerger
from matplotlib.backends.backend_pdf import PdfPages
from os import walk


 
# data to plot
n_groups = 5
means_min = []
means_max = []
pdfs = []
count = 0
 
## TESTCASE ID 0
 
# Open the file  
if int( sys.argv[1] ) == 0: 
    print "Test Case ID 0"    
    fp = open('TESTID_0.txt') # Open file on read mode
elif int( sys.argv[1] ) == 1: 
    print "Test Case ID 1"
    fp = open( 'TESTID_1.txt' )
elif int( sys.argv[1] ) == 2:
    print "Test Case ID 2"
    fp = open( 'TESTID_2.txt' )
elif int( sys.argv[1] ) == 3:
    print "Test Case ID 3"
    fp = open( 'TESTID_3.txt' )
elif int( sys.argv[1] ) == 4:
    allFiles = []
    for (dirpath, dirnames, filenames) in walk(os.getcwd()):
        allFiles.extend(filenames)   
    for pdf_file in allFiles:
        if 'TESTID_0.pdf' == pdf_file:
            pdfs.append( pdf_file )
    for pdf_file in allFiles:
        if 'TESTID_1.pdf' == pdf_file:
            pdfs.append( pdf_file )
    for pdf_file in allFiles:
        if 'TESTID_2.pdf' == pdf_file:
            pdfs.append( pdf_file )
    for pdf_file in allFiles:
        if 'TESTID_3.pdf' == pdf_file:
            pdfs.append( pdf_file )
    merger = PdfFileMerger()
    for pdf in pdfs:
        merger.append(open(pdf, 'rb'))
    with open('result.pdf', 'wb') as fout:
        merger.write(fout)
    sys.exit(0)
    
lines = fp.read().split("\n") # Create a list containing all lines
fp.close() # Close file

print "argument", sys.argv[1]

for line in lines:
    if count < n_groups:
        indexMin = line.find( "Min" )
        indexMax = line.find( "Max" )
        strMin   = line[indexMin+4 : indexMax]
        strMax   = line[indexMax+4 :]
        iVarMin  = long( strMin )
        iVarMax  = long( strMax )
        means_min.append(iVarMin)
        means_max.append(iVarMax)
        print iVarMin, iVarMax 
        count = count + 1
    

# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.35
opacity = 0.8
 
rects1 = plt.bar(index, means_min, bar_width,
                 alpha=opacity,
                 color='b',
                 label='Min')
 
rects2 = plt.bar(index + bar_width, means_max, bar_width,
                 alpha=opacity,
                 color='g',
                 label='Max')
                 
for rect in rects1:
    height = rect.get_height()
    ax.text(rect.get_x() + rect.get_width()/2., 1.0*height,
                '%d' % int(height),
                ha='center', va='bottom')
                
for rect in rects2:
    height = rect.get_height()
    ax.text(rect.get_x() + rect.get_width()/2., 1.0*height,
                '%d' % int(height),
                ha='center', va='bottom')

 
plt.xlabel('Tasks')
plt.ylabel('Time in nanoseconds')
if int( sys.argv[1] ) == 0: 
    plt.title('TESTID_0( Cache delays on normal array fill )')
    pdf = PdfPages(r"TESTID_0.pdf")
elif int( sys.argv[1] ) == 1:  
    plt.title('TESTID_1( Cache delays on normal array fill )')
    pdf = PdfPages(r"TESTID_1.pdf")
elif int( sys.argv[1] ) == 2:  
    plt.title('TESTID_2( Cache delays on normal array fill )')
    pdf = PdfPages(r"TESTID_2.pdf")
elif int( sys.argv[1] ) == 3:  
    plt.title('TESTID_3( Cache delays on normal array fill )')
    pdf = PdfPages(r"TESTID_3.pdf")
else:
    print "Non existent test case"
    
plt.xticks(index + bar_width, ('T0', 'T1', 'T2', 'T3', 'T4' ))
plt.savefig(pdf, format='pdf', bbox_inches = 'tight')
pdf.close()

##TESTCASE ID 0