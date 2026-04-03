-- 세대(GENERATION)별로 id 누구누구 있는지. 알아내기 (with recursion 사용)

-- 해당 재귀 테이블과 ecoli_data를 조인하는데, parent_id에는 없는 id들만 세대별로 뽑아내기

WITH RECURSIVE GENERATION_CTE AS (
    -- base case (parent id가 null)
    SELECT ID, PARENT_ID, 1 AS GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    
    UNION ALL
    
    -- recursive case
    SELECT c.ID, c.PARENT_ID, g.GENERATION + 1
    FROM ECOLI_DATA c
    JOIN GENERATION_CTE g ON g.ID = c.PARENT_ID
)

SELECT
    COUNT(*) AS COUNT,
    GENERATION
FROM GENERATION_CTE
WHERE ID NOT IN (
    SELECT PARENT_ID
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NOT NULL
)
GROUP BY GENERATION
ORDER BY GENERATION ASC;