<?php
const DMS = 17;

function plot($m, $c, &$arr) {
    for ($x = -DMS; $x <= DMS; $x++) {
        if (($m * $x + $c + DMS / 2) < DMS && ($m * $x + $c + DMS / 2) >= 0 && ($x * 2 + DMS) < DMS * 2 + 1 && ($x * 2 + DMS) >= 0) {
            $arr[($m * $x + $c + DMS / 2)][$x * 2 + DMS] = 'x';
        }
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $m = $_POST['m'];
    $c = $_POST['c'];

    if (!is_numeric($m) || !is_numeric($c)) {
        echo "Invalid input. Please enter numeric values for m and c.";
        exit(1);
    }

    $arr = array_fill(0, DMS, array_fill(0, DMS * 2 + 1, ' '));

    for ($i = 0; $i < DMS; $i++) {
        for ($j = 0; $j < DMS * 2 + 1; $j++) {
            $arr[$i][$j] = ($i == DMS / 2 ? '-' : ($j == DMS ? chr(197) : ' '));
        }
    }

    plot($m, $c, $arr);

    echo "<pre>";
    for ($i = 0; $i < DMS; $i++) {
        echo implode('', $arr[$i]) . "\n";
    }
    echo "</pre>";
}
?>