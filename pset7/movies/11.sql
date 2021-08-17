select title from movies
join stars on movies.id = stars.movie_id
join ratings on ratings.movie_id = movies.id
join people on stars.person_id = people.id
where name = 'Chadwick Boseman' order by rating desc limit 5;