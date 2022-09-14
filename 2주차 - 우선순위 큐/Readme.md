# 우선순위 큐
우선순위 큐 ADT는 항목들을 저장한다.

각 항목 : (키,원소)

## 주요 메소드
* **insertItem(k,e)** : 키가 k인 원소 e를 큐에 삽입
* element **removeMin()** : 큐로부터 최소 키를 가진 원소를 삭제하여 반환

## 일반 메소드
* intteger **size()** : 큐의 항목 수를 반환
* boolean **isEmpty()** : 큐가 비어 있는지 여부를 반환

## 접근 메소드
* element **minElement()** : 큐에서 최소 키를 가진 원소를 반환
* element **minKey()** : 큐에서 최소 키를 반환

## 선택 정렬
선택 정렬(selection-sort)은 우선순위 큐가 무순리스트로 구현된다.

#### 실행시간
* **insertItem(k,e)** : O(n)
* **removeMin** : n+(n-1) + (n-2) + ... + 2 + 1
* 실행시간 : O(2n)

## 삽입 정렬
삽입 정렬(insertion-sort)은 우선순위 큐가 순서리스트로 구현된다.
#### 실행시간
* **insertItem(k,e)** : n+(n-1) + (n-2) + ... + 2 + 1
* **removeMin** : O(n)
* 실행시간 : O(2n)
