over_tile = 2400
tear_no_sub = 2900
tear_sub = tear_no_sub + 1120   # 1120 is the extra mats/labor for new subfloor
raw_floor = 1200
mom = 3800
fin_aid = 6800
daycare = 4482
left_over_finaid = fin_aid - daycare
savings = 11000
floor_money = left_over_finaid + savings

# pay mag's mom 200 a month until Jan3, then 1000 from fin aid
worst_case = floor_money - tear_sub - raw_floor - 723 - 3* 200 # 723 is mag's dec loans
print("savings and fin aid in bank, paying all : ", worst_case)
immedately = tear_sub + raw_floor
print("immediately for contractor", immedately)
print("worse case, no_fin aid:", savings - immedately)