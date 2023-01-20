// Author: William Selby
// Retrieve a fasta file using biopython.

#import biopython
import Bio 

#prompt user for the fasta file name
fasta_file = input("Please enter the fasta file name:")

#open the file
f = open(fasta_file, "r") 

#use biopython to read the file
records = Bio.SeqIO.parse(f, "fasta")

#loop through and print the fasta file
for record in records: 
    print(record.id)
    print(record.seq)

#close the file
f.close()
