// Author: William Selby
// this file retrieves a genbank file using biopython

import Bio 
from Bio import SeqIO 

#User Specified Genbank File 
genbank_file = input("Please enter the name of your Genbank file:")

#Open the Genbank file 
try:
    handle = open(genbank_file)
except IOError:
    print("Could not open Genbank file. Please check the file and try again.")

#parse the Genbank file
records = list(SeqIO.parse(handle, "genbank"))

#close the file
handle.close()

# print out the records 
for record in records:
    print(record.id)
    print(record.description)
    print(record.seq)
