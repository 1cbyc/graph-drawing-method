<?php
// I decided to see if I could rewrite this code I wrote in C++ two years ago in PHP, and I think this works
const DMS = 17;

function plot($m, $c, &$arr) {
    for ($x = -DMS; $x <= DMS; $x++) {
        if (($m * $x + $c + DMS / 2) < DMS && ($m * $x + $c + DMS / 2) >= 0 && ($x * 2 + DMS) < DMS * 2 + 1 && ($x * 2 + DMS) >= 0) {
            $arr[($m * $x + $c + DMS / 2)][$x * 2 + DMS] = 'x';
        }
    }
}

$arr = array_fill(0, DMS, array_fill(0, DMS * 2 + 1, ' '));
$m = readline('Enter the gradient (m): ');
$c = readline('Enter the y-intercept (c): ');

if (!is_numeric($m) || !is_numeric($c)) {
    echo "Invalid input. Please enter numeric values for m and c.\n";
    exit(1);
}

for ($i = 0; $i < DMS; $i++) {
    for ($j = 0; $j < DMS * 2 + 1; $j++) {
        $arr[$i][$j] = ($i == DMS / 2 ? '-' : ($j == DMS ? chr(197) : ' '));
    }
}

$arr[DMS / 2][DMS] = chr(197);

plot($m, $c, $arr);

for ($i = 0; $i < DMS; $i++) {
    echo implode('', $arr[$i]) . "\n";
}
?>
