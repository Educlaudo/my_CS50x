-- 4. Number of movies with a 10.0 rating
SELECT COUNT (title) FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE ratings.rating = 10.0;
