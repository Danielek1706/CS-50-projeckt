SELECT DISTINCT p.name
FROM people p
JOIN stars s1 ON p.id = s1.person_id
JOIN movies m1 ON s1.movie_id = m1.id
WHERE m1.id IN (
    SELECT movie_id
    FROM stars
    JOIN people kb ON stars.person_id = kb.id
    WHERE kb.name = 'Kevin Bacon'AND kb.birth = 1958
)
AND p.name != 'Kevin Bacon';
