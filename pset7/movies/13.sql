select distinct(name) from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where title in (select title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where name = 'Kevin Bacon' and birth = 1958) and name <> 'Kevin Bacon' order by name;