# 아두이노 공기청정기
### 회로도
<img width="404" alt="화면 캡처 2022-09-18 212515" src="https://user-images.githubusercontent.com/12439450/190902024-75f61ffb-ec0e-4e3b-9704-742cdc9e9a58.png">

### 사용 부품
Arduino UNO, IRF520, LG공기청정기 필터, 109E2024V0S03(쿨링팬 - 24V 1.9A), PM2008

### 시행착오
1. 컴퓨터 쿨링팬 200mm 로 했으나 풍량이 약해 팬 교환.
2. 산업용 쿨링팬 바꿨으나 팬 속도가 풀rpm으로 돌아가지 않음. - IRF520 부품으로 해결
3. 쿨링팬 소리가 너무 큼 - 팬 주파수를 높였더니 잦아듬. 하지만 약하게 돌리면 소리가 심함.

그래서 소음이 없는 BLDC 모터에 선풍기 팬을 달기로 함.
