<?php

/********************************
        assign9func.php
    	CSCI 466 Assignment 9
		Isabelle Coletti
		z1900409
 *******************************/

//function to display tables from a query's results
function display_table($rows)
{
    //table formatting to look nice
    echo "<table border=1 cell spacing=1 cellpadding=5>";
    echo "<tr>";
    //create a row for the labels
    foreach($rows[0] as $key => $item)
    {
        //print the label
        echo "<th>$key</th>";
    }
    echo "</tr>";
    //create a row for every array in the array of arrays
    foreach($rows as $row)
    {
        echo "<tr>";
        //create a row for every element in the array
        foreach($row as $item)
        {
            //print the data from the element of the array
            echo "<td>$item</td>\n";
        }
        echo "</tr>";
    }
    echo "</table><br/>";
    //end of table
}

?>