<?php 
// $T = $_GET['T'];
// $N = $_GET['N'];
// $K = $_GET['K'];

// echo "Value of T = " . $T . "<br>";
// echo "Value of N = " . $N . "<br>";
// echo "Value of K = " . $K . "<br>";




?>

<form method="post" action="">
<b>T Value: </b><input type="text" name="T">
<input type="submit"> <br>
<b>N Value: </b><input type="text" name="N">
<b>K Value: </b><input type="text" name="K">
<input type="submit">
</form>

<?php

// echo $_POST['T'];
// echo $_POST['N'];
// echo $_POST['K'];

$T = 2;
$N = array(3,5);
$K = array(1,2);

//input constraints here
// 1≤T≤50! 1≤N≤100000! 0≤K<N!


$A = array(array());

//laying the first set of values
for ($i=0; $i < $T; ++$i) { 
	for ($j=0; $j < $N[$i]; ++$j) { 
		$A[$i][$j] = $j;
	}
}

//echoing the arrays before it starts
echo '<br>Arrangement before it starts reversing<br>';
for ($i=0; $i < $T; ++$i) { 
	for ($j=0; $j <$N[$i] ; ++$j) { 
		echo $A[$i][$j];
	}
	echo "<br>";
}

//Manipulation starts here
echo "Manipulation starts here<br>";
for ($k=0; $k < $T; ++$k) { 
	echo 'T = '. ($k+1) . '<br>';
	
	for ($i=0; $i < $N[$k]; ++$i) { 
		
		for ($j=0; $j < (($N[$k]-$i)/2); ++$j) { 
			
			$t = $A[$k][$i+$j];
			$A[$k][$i+$j] = $A[$k][$N[$k]-1-$j];
			$A[$k][$N[$k]-1-$j] = $t;
		
		}
		//print out
		for ($j=0; $j <$N[$k] ; ++$j) { 
		echo $A[$k][$j];
		}
		echo "<br>";
	}
}

//Search for K value and Print the index out
for ($j=0; $j < $T; ++$j) { 
	for ($i=0; $i < $N[$j] ; ++$i) { 
		if ($A[$j][$i] == $K[$j]) {
			echo  'T = ' . ($j+1) . " , value of ". $K[$j] . ' , is at index ' . $i;
			echo "<br>";
		}
	}
}



?>