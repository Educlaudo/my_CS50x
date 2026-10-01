-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred

SELECT DISTINCT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
WHERE movies.id IN (
                        (SELECT movie_id
                         FROM stars
                         WHERE stars.person_id =
                                 (SELECT id
                                  FROM people
                                  WHERE name = 'Jennifer Lawrence')))
    AND movies.id IN
        (SELECT movie_id
         FROM stars
         WHERE stars.person_id =
                 (SELECT id
                  FROM people
                  WHERE name = 'Bradley Cooper'))
