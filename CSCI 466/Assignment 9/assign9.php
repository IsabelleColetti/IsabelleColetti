<!-- **************************
		assign9.php
		CSCI 466 Assignment 9
		Isabelle Coletti
		z1900409
*************************** -->

<html><head><title>Assignment 9</title></head>
<body>
<!-- display the header and information about how the page works -->
<h1>Supplier and Parts Form</h1>
<p><font size="+1">Below are several forms with options to display information, make purchases, and add things to the databases.
	 <br/>The results will be displayed at the bottom of this page after submission.</font></p>
<p><font>Created by: Isabelle Coletti - z1900409</font></p>
<p> -------------------------------------------------------------------------------------------------------------------------------------------------------</p>

<?php

	//include username and password
	include('secret.php');
	//include print function
	include('assign9func.php');

	try		//try to connect to the database
	{
		$dsn = "mysql:host=courses;dbname=z1900409";
		$pdo = new PDO($dsn, $username, $password);

		/*
			Show all of the suppliers and their details.
			Show all of the parts and their details.
		*/

		echo "<h3>Select what table(s) you would like to display:</h3>";
		echo "<form method='POST'/>";
		//show a checkbox for suppliers
		echo "<input type='checkbox' name='Suppliers' value='Show Suppliers'/> Show Suppliers";
		//show a checkbox for parts
		echo "<input type='checkbox' name='Parts' value='Show Parts'/> Show Parts";
		echo "<br/>";

		//fetch all the parts in the table
		$result = $pdo->query("SELECT P,PNAME,COLOR FROM P;");
		$parts = $result->fetchAll(PDO::FETCH_ASSOC);
		
		/*
			Form that allows a user to select a part and see everyone who supplies that part, along with how many of
			that part they have available. The other information on the part chosen is shown as well.
		*/
		echo "<br/>";
		echo "<h3>Select part(s) you would like to see information about:</h3>";
		//loop through every part in the table
		foreach($parts as $part)
		{
				$arr = [];
				$arr[0] = $part['PNAME'];
				$arr[1] = $part['COLOR'];
				//use checkboxes so user can select multiple parts to display info about
				//show a checkbox for every unique part in the table
				echo "<input type='checkbox' name='$arr[1]$arr[0]' value='$arr[1] $arr[0]'/> $arr[1] $arr[0]";
			
		}
		echo "<br/><br/>";

		//fetch all the suppliers in the table
		$result = $pdo->query("SELECT S FROM S;");
		$supp = $result->fetchAll(PDO::FETCH_ASSOC);

		/*
			Form that allows a user to select a supplier and display a list of all of the parts they supply and how many of
			each they have. Information on the supplier chosen is also be displayed. 
		*/

		echo "<h3>Select supplier(s) you would like to see information about:</h3>";
		//loop through every supplier in the table
		foreach($supp as $supplier)
		{
				$arr = [];
				$arr[0] = $supplier['S'];
				//use checkboxes so user can select multiple suppliers to display info about
				//show a checkbox for every unique part in the table
				echo "<input type='checkbox' name='$arr[0]' value='$arr[0]'/> $arr[0] ";
			
		}
		echo "<br/><br/>";

		//add a submit button for this form
		echo "<input type='submit' name='partsubmit' value='Submit'/>";
		echo "</form>";
		echo "<p> -------------------------------------------------------------------------------------------------------------------------------------------------------</p>";
		
		//new form for the purchases
		echo "<form method='POST'>";
		echo "<h3>Select a part and a supplier to make a transaction:</h3>";

		//display the parts to choose from
		echo "<h4>Please choose one part to purchase:</h4>";
		//loop through every part in the table
		foreach($parts as $part)
		{
				$arr = [];
				$arr[0] = $part['PNAME'];
				$arr[1] = $part['COLOR'];
				//use radio boxes so user can only choose one part
				//show one radio box for every unique part in the table
				echo "<input type='radio' name='partPurchase' value='$arr[1] $arr[0]'/> $arr[1] $arr[0]";
			
		}

		//display the suppliers to choose from
		echo "<h4>Please choose one supplier to purchase from:</h4>";
		//loop through every supplier in the table
		foreach($supp as $supplier)
		{
				$arr = [];
				$arr[0] = $supplier['S'];
				//use radio boxes so user can only choose one part
				//show a radio box for every unique supplier in the table
				echo "<input type='radio' name='supPurchase' value='$arr[0]'/> $arr[0] ";
			
		}
		
		//let the user enter a number of parts to purchase, with a minimum of 0
		echo "<h4>Quantity you would like to purchase:</h4>";
		echo "<input type='number' name='amtpurchased' min='0'/>";
		echo "<br/><br/>";

		//add a submit button for this form
		echo "<input type='submit' name='transsubmit' value='Submit'/>";
		echo "</form>";
		echo "<p> -------------------------------------------------------------------------------------------------------------------------------------------------------</p>";

		//count the number of parts currently in the database
		$result = $pdo->query("SELECT COUNT(P) FROM P;");
		$partscnt = $result->fetch(PDO::FETCH_ASSOC);
		$Pcount = $partscnt['COUNT(P)'];
		//increment to suggest correct part ID
		$Pcount++;

		//new form for adding parts
		echo "<form method='POST'>";
		echo "<h3>Enter the information below to add a new part to the database:</h3>";
		echo "<h4>Part ID (Suggested ID is provided):</h4>";

		//text field for user input of part ID with suggested value
		echo "<input type='text' name='partID' value='P$Pcount'/>";
		echo "<h4>Part name:</h4>";

		//text field for user input of part name
		echo "<input type='text' name='partName'/>";
		echo "<h4>Part color:</h4>";

		//text field for user input of part color
		echo "<input type='text' name='partColor'/>";
		echo "<h4>Part Weight:</h4>";

		//number field for user input of part weight with minimum of 0
		echo "<input type='number' name='partWeight' min='0'/>";
		
		echo "<br/><br/>";

		//add a submit button for this form
		echo "<input type='submit' name='addsubmit' value='Submit'/>";
		echo "</form>";
		echo "<p> -------------------------------------------------------------------------------------------------------------------------------------------------------</p>";

		//new form for adding supply of parts
		echo "<form method='POST'>";
		echo "<h3>Select/Enter the information below to add a supply of a part into the database:</h3>";

		//display the parts to choose from
		echo "<h4>Please choose the part being supplied:</h4>";
		//loop through every part in the table
		foreach($parts as $part)
		{
				$arr = [];
				$arr[0] = $part['PNAME'];
				$arr[1] = $part['COLOR'];
				//use radio boxes so user can only choose one part
				//show one radio box for every unique part in the table
				echo "<input type='radio' name='partAdd' value=".$part['P']." /> $arr[1] $arr[0]";
			
		}

		//display the suppliers to choose from
		echo "<h4>Please choose the supplier supplying the part:</h4>";
		//loop through every supplier in the table
		foreach($supp as $supplier)
		{
				$arr = [];
				$arr[0] = $supplier['S'];
				//use radio boxes so user can only choose one part
				//show one radio box for every unique supplier in the table
				echo "<input type='radio' name='supAdd' value='$arr[0]'/> $arr[0] ";
			
		}

		echo "<h4>Quantity being supplied:</h4>";

		//number field for user input of quantity with minimum of 0
		echo "<input type='number' name='amtAdd' min='0'/>";
		
		echo "<br/><br/>";

		//display submit button for form
		echo "<input type='submit' name='supplysubmit' value='Submit'/>";
		echo "</form>";
		echo "<p> -------------------------------------------------------------------------------------------------------------------------------------------------------</p>";

		//process the inputs here
		if ($_SERVER['REQUEST_METHOD'] === 'POST')
		{
			//display suppliers or parts based on which button was submitted
			if (($_POST['Suppliers']))
			{
				//get all the suppliers information
				$result = $pdo->query("SELECT * FROM S;");
				$rows = $result->fetchAll(PDO::FETCH_ASSOC);
		
				//if there is no information, display that
				if(empty($rows))
					echo "<p>There is no information available.</p><br/>";
				else	//otherwise
				{
					//display the suppliers table
					echo "<h1>The suppliers table:</h1>";
					display_table($rows);
				}
			}
			if (($_POST['Parts']))
			{		
				//get all the parts information
				$result = $pdo->query("SELECT * FROM P;");
				$rows = $result->fetchAll(PDO::FETCH_ASSOC);
		
				//if there is no information, display that
				if(empty($rows))
					echo "<p>There is no information available.</p><br/>";
				else	//otherwise
				{
					//display the parts table
					echo "<h1>The parts table:</h1>";
					display_table($rows);
				}
			}

			/*
			Form that allows a user to select a part and see everyone who supplies that part, along with how many of
			that part they have available. The other information on the part chosen is shown as well.
			*/

			//loop through every part to see if it was selected
			foreach($parts as $part)
			{
				//save the part name and color into an array
				$arr = [];
				$arr[0] = $part['PNAME'];
				$arr[1] = $part['COLOR'];
				//check if the part was selected
				if (($_POST["$arr[1]$arr[0]"]))
				{
					//save the part ID
					$partID = $part['P'];

					//get the information about the selected part
					$prePart = $pdo->prepare('SELECT * FROM P WHERE P = ?');
					$prePart->execute(array($partID));
					$rows = $prePart->fetchAll(PDO::FETCH_ASSOC);

					echo "<h2>Information about $arr[1] $arr[0]:</h2>";
					if(empty($rows))	//if there is no information for the part, display that
						echo "<p>There is no information for this part.</p><br/>";
					else	//otherwise
					{
						//display the part information
						display_table($rows);
					}

					//get the information about who supplies the part
					$preSupplier = $pdo->prepare("SELECT SNAME AS 'SUPPLIER NAME', SP.S AS 'SUPPLIER', QTY AS 'QUANTITY AVAILABLE' FROM S,SP WHERE SP.P = (SELECT P FROM P WHERE P = ?) AND S.SNAME = (SELECT SNAME FROM S WHERE S = SP.S)");
					$preSupplier->execute(array($partID));
					$rows = $preSupplier->fetchAll(PDO::FETCH_ASSOC);

					if(empty($rows))	//if no one supplies it, display that
						echo "<p>No supplier supply this part.</p><br/>";
					else	//otherwise
					{
						//display information about who supplies the part
						echo "<h2>Suppliers who supply this part:</h2>";
						display_table($rows);
					}
				}	
			}
			
			//loop through every supplier to see if it was selected
			foreach($supp as $supplier)
			{
				//save the supplier ID into a variable
				$supID = $supplier['S'];
				//check if the supplier was selected
				if (($_POST[$supID]))
				{
					//get the information about the selected supplier
					$preSupp = $pdo->prepare('SELECT * FROM S WHERE S = ?');
					$preSupp->execute(array($supID));
					$rows = $preSupp->fetchAll(PDO::FETCH_ASSOC);

					echo "<h2>Information about $arr[0]:</h2>";
					if(empty($rows))	//if there is no information about the supplier, display that
						echo "<p>There is no information for this supplier.</p><br/>";
					else	//otherwise
					{
						//display the supplier information
						display_table($rows);
					}

					//get the information about the parts they supply
					$preParts = $pdo->prepare("SELECT SP.P AS 'PART', P.PNAME AS 'PART NAME', P.COLOR AS 'PART COLOR', SP.QTY AS 'QUANTITY' FROM 
					SP,P WHERE S = (SELECT S FROM S WHERE S = ?) AND P.PNAME = (SELECT PNAME FROM P WHERE P = SP.P) AND P.COLOR = (SELECT COLOR 
					FROM P WHERE P = SP.P)");
					$preParts->execute(array($supID));
					$rows = $preParts->fetchAll(PDO::FETCH_ASSOC);

					if(empty($rows))	//if they do not supply any parts, display that
						echo "<p>This supplier does not supply any parts.</p><br/>";
					else	//otherwise
					{	
						//display information about the parts they supply
						echo "<h2>Parts supplied by this supplier:</h2>";
						display_table($rows);
					}
				}
			}
		
			//check if all 3 fields for the purchase form are filled and the purchase submit button is entered
			if(($_POST['partPurchase']) and ($_POST['supPurchase']) and ($_POST['amtpurchased']) and ($_POST['transsubmit']))
			{
				//prepare the update statement for the purchase
				$prepared = $pdo->prepare("UPDATE SP SET QTY = ? WHERE S = ? AND P = ?;");

				//save the part's name and color
				$partSelected = $_POST['partPurchase'];

				//separate the part's name from the part's color
				$needle = " ";
				$pcolor = strstr($partSelected, $needle, true);
				$pname = str_replace($pcolor, "", $partSelected);
				$pname = substr($pname, 1);

				//save the supplier to purchase from
				$supSelected = $_POST['supPurchase'];

				//save the amount to purchase
				$amount = $_POST['amtpurchased'];
				
				//get the part's ID based on its name and color
				$preP = $pdo->prepare("SELECT P FROM P WHERE PNAME = ? AND COLOR = ?");
				$preP->execute(array($pname, $pcolor));
				$row = $preP->fetch(PDO::FETCH_ASSOC);
				//save the part's ID
				$p = $row['P'];

				//get the current quantity of the part supplied by the supplier
				$preP = $pdo->prepare("SELECT QTY FROM SP WHERE S = ? AND P = (SELECT P FROM P WHERE PNAME = ? AND COLOR = ?)");
				$preP->execute(array($supSelected, $pname, $pcolor));
				$row = $preP->fetch(PDO::FETCH_ASSOC);
				//save the current quantity
				$QTY = $row['QTY'];

				//if the amount to be purchased is too large
				if($QTY < $amount)
				{
					//display error message and exit
					echo "$supSelected does not have $amount $partSelected" . "s in stock. Please try again.";
					exit();
				}
				else	//otherwise
				{
					//subtract the amount to purchase from the current quantity
					$newQTY = $QTY - $amount;
				}
				
				//execute prepared statement to update the quantity in the table
				$success = $prepared->execute(array($newQTY, $supSelected, $p));

				if($success)	//if successful, display how many of the part were bought
					echo "You bought $amount $partSelected" . "(s) from $supSelected.";
				else	//otherwise
				{
					//display error message and exit
					echo "Error completing purchase.";
					exit();
				}
			}
			else if ($_POST['transsubmit'])		//if all 3 fields were not filled and the submit button was entered
			{
				//display error message and exit
				echo "You must select a part, supplier, and enter a quantity to make a purchase. Please try again.";
				exit();
			}

			//check if all 4 fields for the adding part form are filled and the adding part submit button is entered
			if(($_POST['partName']) and ($_POST['partColor']) and ($_POST['partWeight']) and ($_POST['partID']) and ($_POST['addsubmit']))
			{
				//prepare insert statement to add the part to the parts table
				$prepared = $pdo->prepare("INSERT INTO P (P, PNAME, COLOR, WEIGHT) VALUES(?, ?, ?, ?);");

				//save the part ID
				$partID = $_POST['partID'];

				//save the part name
				$partName = $_POST['partName'];

				//save the part color
				$partColor = $_POST['partColor'];

				//save the part weight
				$partWeight = $_POST['partWeight'];
			
				//execute the prepared statement to insert the part into the table
				$success = $prepared->execute(array($partID, $partName, $partColor, $partWeight));
				if($success)	//if successful, display what part was added 
					echo "Successfully added $partColor $partName with ID = $partID and Weight = $partWeight to the database.";
				else	//otherwise
				{
					//display error message and exit
					echo "Error adding part.";
					exit();
				}
			}
			else if ($_POST['addsubmit'])	//if all 4 fields were not filled and the submit button was entered
			{
				//display error message and exit
				echo "All 4 fields must be filled in to add a new part to the database. Please try again.";
				exit();
			}
			
			//check if all 3 fields for the adding supply form are filled and the adding supply submit button is entered
			if(($_POST['supplysubmit']) and ($_POST['partAdd']) and ($_POST['supAdd']) and ($_POST['amtAdd']))
			{
				//prepare the insert statement for parts that are not already in the SP table with the supplier
				$preparedInto = $pdo->prepare("INSERT INTO SP VALUES(?, ?, ?)");
				
				//prepare the update statement for parts that are already in the SP table with the supplier
				$prepared = $pdo->prepare("UPDATE SP SET QTY = ? WHERE S = ? AND P = ?;");

				//save the part ID
				$partToAdd = $_POST['partAdd'];

				//save the supplier ID
				$supToAdd = $_POST['supAdd'];

				//save the amount to add (quantity)
				$amtToAdd = $_POST['amtAdd'];

				//get the part's name and color based on its ID
				$prepare = $pdo->prepare("SELECT PNAME, COLOR FROM P WHERE P = ?");
				$prepare->execute(array($partToAdd));
				$f = $prepare->fetch(PDO::FETCH_ASSOC);
				//store the part name
				$pname = $f['PNAME'];
				//store the part color
				$pcolor = $f['COLOR'];				

				//check if the part is already in the SP table with the supplier
				$prepare = $pdo->prepare("SELECT P FROM SP WHERE P = ? AND S = ?");
				$prepare->execute(array($partToAdd, $supToAdd));
				$res = $prepare->fetch(PDO::FETCH_ASSOC);
				if(empty($res))		//if the part is not in the table yet
				{
					//execute the insert statement to add the part to the table
					$success = $preparedInto->execute(array($supToAdd, $partToAdd, $amtToAdd));
					if($success)	//if successful display how much of the part was added to what supplier
					{
						echo "Successfully added $amtToAdd of $pcolor $pname supplied by $supToAdd to the database.";
					}
					else	//otherwise
					{	
						//display error message and exit
						echo "Error adding supply.";
						exit();
					}
				}
				else	//if the part is already in the table
				{
					//get the current quantity of the part in the table with the supplier
					$qprepare = $pdo->prepare("SELECT QTY FROM SP WHERE P = ? AND S = ?");
					$qprepare->execute(array($partToAdd, $supToAdd));
					$res = $qprepare->fetch(PDO::FETCH_ASSOC);
					//save the current quantity
					$quantity = $res['QTY'];
					//calculate the amount to update the quantity to
					$newamtToAdd = $quantity + $amtToAdd;

					//execute the update statement to update the quantity of the part with the supplier
					$success = $prepared->execute(array($newamtToAdd, $supToAdd, $partToAdd));
					if($success)	//if successful display how much of the part was added to what supplier
					{
						echo "Successfully added $amtToAdd of $pcolor $pname supplied by $supToAdd to the database.";
					}
					else	//otherwise
					{
						//display error message and exit
						echo "Error adding supply.";
						exit();
					}
				}
			}
			else if ($_POST['supplysubmit'])	//if all 3 fields were not filled and the submit button was entered
			{
				//display error message and exit
				echo "You must select a part, supplier, and enter a quantity to add to the database. Please try again.";
				exit();
			}
			
		}

		
	}
	catch(PDOexception $e)		//if connection fails, display error message
	{
		echo "Connection to database failed: " . $e->getMessage();
	}

?>
</body>
</html>
