<?php 

$T = $_GET['T'];
$N = $_GET['N'];
$K = $_GET['K'];
$checkN = array();
$checkK = array();

// 1≤T≤50! 1≤N≤100000! 0≤K<N!

function check($N,$K,&$checkK,&$checkN) {
	
	//check the constraint for N
	foreach ($N as $n => $value) {
		if (($value < 1) or ($value > 100000)) {
			$checkN[$n] = 0;								//N invalid, stores 0.
			echo "N" . ($n+1) . " is invalid.  <br>";  
		}
		else{
		 	$checkN[$n] = 1;       							//N valid, stores 1.
		}
	}

	//check the constraint for K 
	foreach ($K as $k => $value) {
		if (($value<0) or ($value >= $N[$k])){  
			$checkK[$k] = 0;								//k invalid, store 0.
			echo "K" . ($k+1) . " is invalid.  <br>";
		}
		else{
			$checkK[$k] = 1;								//k is valid, store 1. 
		}
	}
	return true;						
}

check($N,$K,$checkK,$checkN); 								//Function is called here to check the inputs constraints.

for ($z=0; $z <$T ; $z++) { 
	if (($checkN[$z] == 1) and ($checkK[$z] == 1)) {

		$A = array(array());

		//set up the intial values before reversing.
		for ($j=0; $j < $N[$z]; ++$j) { 
				$A[$z][$j] = $j;
			}
		

		//reversing starts here
		for ($i=0; $i < $N[$z]; ++$i) { 
						
			for ($j=0; $j < (($N[$z]-$i)/2); ++$j) { 
							
				$t = $A[$z][$i+$j];
				$A[$z][$i+$j] = $A[$z][$N[$z]-1-$j];
				$A[$z][$N[$z]-1-$j] = $t;
						
			}
		}

		//Search for K value and echo the index out
			for ($i=0; $i < $N[$z] ; ++$i) { 
				if ($A[$z][$i] == $K[$z]) {
					echo  'Test ' . ($z+1) . " , value of ". $K[$z] . ' , is at index ' . $i;
					echo "<br>";
				}
			}
	}

	else{
		echo "Please check and re-enter it again!<br>";
	}
}


?>