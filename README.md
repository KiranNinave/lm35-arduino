# TTT

## The main goal of the algorithm is to Maximize happiness and Minimize overall unhappiness and also prevent writers from leaving TTT.

1. For making them Happy I am considering I need to published At most 50% of every writer's post every month.
2. For minimize overall unhappiness I am going to predict writers share for that month using Happy Index
3. For preventing writers leaving TTT I am going to publish At most minimum 1 tale of every writer who had make less contribution
4. For giving higher priority to the writers who does more contribution to TTT. I am going to publish their content with less waiting time.

### considerations

1. Days of month = 30
2. Per day tales publish rate = 10
3. TTT going to pay writers on Monthly basis

### Happy and Unhappy Index

1. we can calculate Happy index using formula **happy index = ( Days of month \* Per day publish )/Total tales** ex: (30\*10)/562 = 0.53
1. happy index range 0 to 1
1. unhappy index = 1 - happy index

### using happy index

1. By using happy index we can calculate writers share for that particular month by using formula **Writer share = Math.round( total_writer_tales \* happy index )**.
2. we also need to prevent writers from leaving TTT, so for the writer whose share is Less than 1, we will consider it as 1.

### Identifying unhappiness

1. Because of rounding we might get more shares (tales) to be published for that month. So we can find extra shares by using formula **extra shares = share.total-300**
2. the number of extra shares are the number of writers who is going to be unhappy.
3. As we need to give slightly higher priority to the writers who are more often on TTT and also prevent writers from leaving TTT. we are going to deduct this extra shares from writers who did less contribution to TTT and holing more than 1 shares(tales).

### scheduling

1. The writers who make more contributions to TTT might be popular writers on TTT and people might be waiting for their tales. So I am going publish their contain with less waiting time.
2. For scheduling first thing is to calculate waiting time between publishing two tales of a individual writers.
3. The writers who holds more than 30 ( number of days in month ) shares(tales) for that particular month for them **waiting time = 1 ( we are going to publish next tale by 1 day )**
4. The writers who holds less than 30 (number of days in month) shares(tales) for that particular month for them **waiting time = 30 / shares**
5. After calculating waiting time for each writer. For every writer start publishing their tale from day 1 , next post on day 1 + waiting time as it continue till finish all the posts
6. As for each day we can publish at most 10 tales, If particular day’s tales are full then check availability for the next day.
7. While iterating if you go beyond 30 (number of days in month) then again start from 1 day till we completely schedule all the tales

### how writers become happy?

For every writer my algorithm is publishing **( total_writer_tales \* happy index ) %** tales
So the earnings of every writer will be in the same ratio. The writer who does more contribution to TTT will earn more. But the writers does less contribution also earn In same proportion

### What about writers who are more often on TTT?

The writers who are more often on TTT will have more contribution on TTT. so for them their content will appear more often on TTT with less waiting time.

### code Explanation

1. **filterData()** : Function will aggregate writers tales and calculate total tales for every writer. This function will take data from excel sheet and return map of writer vs tales

2. **sortData()** : Function will take a map from **filterData()** and return array of writer and their tales based on descending order of total tales of that writer

3. **getShare()**: Function accepts sortedData and Happy Index based on that calculate Individual writers share for that particular month .

4. **acjustExtras()** : If total shares for that month exceeding the limit of 300(maximum number of tales can be publish in That month) then this function will remove share from lower priority writers but not make them zero

5. **scheduling()** : Function will return multidimensional array of size 30x10 contain talles to be publish on that day by using waiting time as decision factor

# note : for output of this code please check 1-month-share.json, 2-month-share.json, 1-month-shcedule.json, 2-month-shedule.json
