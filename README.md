Flat profile


| %time | cumulative  seconds | self seconds | calls    | self  s/call | total s/call | name               |
|-------|---------------------|--------------|----------|--------------|--------------|--------------------|
| 72.64 | 3.93                | 3.93         | 37673894 | 0.00         | 0.00         | comparator         |
| 16.82 | 4.84                | 0.91         | N/A      | N/A          | N/A          | main               |
| 6.10  | 5.17                | 0.33         | 999999   | 0.00         | 0.00         | merge              |
| 3.14  | 5.34                | 0.17         | 1        | 0.17         | 2.17         | quick_sort         |
| 0.92  | 5.39                | 0.05         | 1        | 0.05         | 2.33         | merge_sort_recurse |
| 0.37  | 5.41                | 0.02         | 524287   | 0.00         | 0.00         | swap               |
| 0.00  | 5.41                | 0.00         | 1        | 0.00         | 2.33         | merge_sort         |


Call graph (explanation follows)


granularity: each sample hit covers 4 byte(s) for 0.18% of 5.41 seconds

index | % time  |  self | children  |  called  |   name
----- | ------- | ----- | --------- | -------- | --------
      |         |       |           |          |     <spontaneous>
[1]   | 100.0    |0.91   | 4.50       |          |main [1]
      |          |0.00   | 2.33       |1/1        |   merge_sort [3]
      |          |0.17   | 2.00      | 1/1         |  quick_sort [6]
      |          |       |          |               |
      |          |1.95    |0.00 |18673875/37673894    | merge [5]
      |          |1.98    |0.00 |19000019/37673894    | quick_sort [6]
[2]   |  72.6    |3.93    |0.00 |37673894         |comparator [2]
      |          |        |           |           |
      |          |0.00    |2.33       |1/1           |main [1]
[3]     |43.0    |0.00    |2.33       |1         |merge_sort [3]
       |         |0.05    |2.28       |1/1         |  merge_sort_recurse [4]
       |         |        |           |             |
        |        |        |     |1999998            | merge_sort_recurse [4]
        |        |0.05    |2.28   |    1/1          | merge_sort [3]
[4]     |43.0    |0.05    |2.28   |    1+1999998 |merge_sort_recurse [4]
        |        |0.33    |1.95  |999999/999999   |   merge [5]
        |         |        |    |1999998           |  merge_sort_recurse [4]
        |        |         |     |                  |
        |        |0.33    |1.95  |999999/999999      |merge_sort_recurse [4]
[5]     |42.1    |0.33    |1.95  |999999         |merge [5]
        |        |1.95    |0.00 |18673875/37673894   |  comparator [2]
        |        |         |     |                   |
         |      |         |      |524286             |quick_sort [6]
         |      | 0.17    |2.00  |     1/1           |main [1]
[6]     |40.1   | 0.17    |2.00  |     1+524286  |quick_sort [6]
        |       | 1.98    |0.00 |19000019/37673894   |  comparator [2]
        |       | 0.02    |0.00 | 524287/524287      |swap [7]
        |       |         |     | 524286             |quick_sort [6]
        |        |        |      |                   |
        |        |0.02    |0.00  |524287/524287     | quick_sort [6]
[7]     | 0.4    |0.02    |0.00  |524287        | swap [7]
        |        |        |      |              |    




Flat profile:

Each sample counts as 0.01 seconds.


  %   |cumulative |  self   |          | self     |total    |       
 time |  seconds  | seconds |    calls |  s/call  | s/call  |name  
----- | --------- | ------- | -------- | -------- | ------- | ----  
 79.18|      3.27  |   3.27 | 26616723   |  0.00  |   0.00 | comparator
 12.83|      3.80 |    0.53 |          |          |       | main
  7.14|      4.09 |    0.29 |       1  |   0.29   |  3.60 | quick_sort
  0.85|      4.13 |    0.04 | 4911136  |   0.00   |  0.00 | swap  


Call graph (explanation follows)


granularity: each sample hit covers 4 byte(s) for 0.24% of 4.13 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.53    3.60                 main [1]
                0.29    3.31       1/1           quick_sort [2]
-----------------------------------------------
                              890487             quick_sort [2]
                0.29    3.31       1/1           main [1]
[2]     87.2    0.29    3.31       1+890487  quick_sort [2]
                3.27    0.00 26616723/26616723     comparator [3]
                0.04    0.00 4911136/4911136     swap [4]
                              890487             quick_sort [2]
-----------------------------------------------
                3.27    0.00 26616723/26616723     quick_sort [2]
[3]     79.2    3.27    0.00 26616723         comparator [3]
-----------------------------------------------
                0.04    0.00 4911136/4911136     quick_sort [2]
[4]      0.8    0.04    0.00 4911136         swap [4]
-----------------------------------------------


