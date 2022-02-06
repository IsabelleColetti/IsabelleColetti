#!/bin/bash

#
# CSCI 330 Section 1
# Assignment 8
# Created by Isabelle Coletti (z1900409)
# z1900409.awk
#

#do this before any records are read in
BEGIN {
		#set field separator to colon
		FS=":"
		#create counters and initialize to 0
		numAssoc=0
		numProd=0
		numTrans=0

		#print the header for the table
		printf("%s\n\n", "Summary of Sales for 2020")
		printf("%-19s %-5s %7s\n", "Name", "ID", "Sales")
		#print ='s for the top of the table
		printf("=================================\n")
}
#if the number of fields is 3
NF == 3 { 
		#add one to the associate counter
		numAssoc++
		#split the name of the associate using a space as separator
		split($2,nm," ")
		#save the name of the associate in order of last, first
		#save name into associate array in index of their ID
		associates[$1] = nm[2] ", " nm[1]
}
#if the number of fields is 4
NF == 4 {
		#add one to the product counter
		numProd++
		#save the product's price into its respective ID index in array
		products[$1] = $4
}
#if the number of fields is 5
NF == 5 {
			#split the date into separate fields with the / as a separator
			split($4,a,"/")

			#add one to the transaction counter
			numTrans++
			
			#check if the third value of the split array is 2020 to make sure the transaction
			#was made in the year 2020
			if ( a[3] == 2020 )
			{
				#check if the product ID is one inside the products array
				if ( $2 in products )
				{
					#if so, add product price * quantity to the sales array in the index of the associate ID
					sales[$3] += products[$2]*$5
				}
			}
}
#after all of the records have been read in
END {
		#loop through all of the salex indexes
		for (x in sales) {
			#print the associate name, associate ID and sales amount in descending order by using pipe
			printf("%-20s %d %10.2f\n", associates[x], x, sales[x]) | "sort -nr -k 4"
		}

		#close pipe
		close("sort -nr -k 4")
		#print ='s for the bottom of the table
		printf("=================================\n")

		#insert some tabs for formatting
		printf("\t\t  ")
		#print the number of associates
		printf("%2d" "%s\n", numAssoc, " Associates")

		#insert some tabs for formatting
		printf("\t\t  ")
		#print the number of products
		printf("%2d" "%s\n", numProd, " Products")

		#insert some tabs for formatting
		printf("\t\t  ")
		#print the number of transactions
		printf("%2d" "%s\n", numTrans, " Transactions")
}
