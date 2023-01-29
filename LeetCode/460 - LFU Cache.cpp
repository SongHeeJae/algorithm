/*
LFU > LRU 순으로 캐시를 구현하는 문제였습니다.

get과 put 연산은 O(1)의 시간복잡도를 가져야하기 때문에, 해시테이블(unordered_map)과 링크드리스트(list)를 이용할 수 있습니다.

key 접근 횟수에 대응하는 key 목록을 저장하는, unordered_map({count} = {keyList}) counters를 선언해줍니다.
또한, 각 key에 대해 value, count, counters에서 대응하는 리스트의 포인터를 저장하는,
unordered_map({key} = {value, count, counterPointer}) items를 저장해줍니다.

캐시에 저장된 개수가 capacity에 도달하면, counters에서 캐시 만료 대상을 즉시 찾아줄 수 있습니다.
전체 엔트리의 최소 접근 횟수 minCount를 기억하고 있으면, counters[minCount]에 저장된 리스트 구조를 이용하면 되기 때문입니다.
새롭게 접근되는 엔트리를, counters에서 접근 횟수에 대응하는 리스트의 맨 앞에 넣으면,
counter[minCount]의 맨 뒤에 있는 엔트리가 캐시 만료 대상입니다.

get이 호출될 때에는, items[key]에서 대응하는 counters 포인터를 찾아서 제거해주고,
새로운 접근 횟수와 포인터를 items와 counters에 업데이트 해주면 됩니다.
전체 엔트리의 최소 접근 횟수 minCount에 대응하는 리스트가 비게 된다면, 현재의 접근 횟수로 minCount를 지정해줍니다.
 
put이 호출될 때에는,
기존에 이미 key가 있을 경우 접근 횟수를 업데이트하면서 value 또한 교체해줍니다.
캐시에 저장된 개수가 capacity에 도달했다면, counters[minCount]에서 맨 뒤에 있는 엔트리를 제거해줍니다.
이 때에도, minCount를 적절하게 업데이트해줍니다.
새롭게 저장되는 엔트리는 접근 횟수를 1로 초기화해줍니다.
*/
