db.employee_blank.insertMany([
    {
        'name': 'Иван', 
        'sername': 'Иванов', 
        'father_name': 'Иванович', 
        'email': 'ivan@gmail.com', 
        'telefone_number': '8(777)111-11-11',
        'information': {'birthday': '1987-10-10',' interests': ['плавание', 'шахматы', 'книги']}, 
        'prikaz': {
			    "Номер уведомления": 123
		    }
    },

    {
        'name': 'Николай', 
        'sername': 'Семерук', 
        'father_name': 'Александрович', 
        'email': 'killer@rambler.ru', 
        'telefone_number': '7(777)523-68-91',
        'information': {'birthday': null,' interests': ['бокс', 'компьютерные игры', 'шашки' ]}, 
        'prikaz':{
			"Номер приказа": 1001
		}
    },
    {
        'name': 'Александр', 
        'sername': 'Хопта', 
        'father_name': 'Петрович', 
        'email': 'sasha@.ru', 
        'telefone_number': '(2-20-47)',
        'information': {'birthday': '1987-07-10',' interests': ['плавание', 'компьютерные игры']},  
        'prikaz': {
			"Номер распоряжения": 202
		}
    },
    {
        'name': 'Владимир', 
        'sername': 'Никифоров', 
        'father_name': 'Александрович', 
        'email': 'vova@rambler.ru', 
        'telefone_number': '2-45-48',
        'information': {'birthday': '1967-07-12',' interests': ['плавание', 'стрельба из лука']},   
        'prikaz': {
			"Номер приказа": 404
		}
    },
    {
        'name': 'Семен', 
        'sername': 'Лобанов', 
        'father_name': 'Иванович', 
        'email': 'semen@yandex.com', 
        'telefone_number': '8(777)654-12-21',
        'information': {'birthday': '1987-01-10',' interests': ['борьба', 'шашки', 'воллейбол', 'футбол']},  
        'prikaz': {
			"Номер приказа": 15
		}
    },
    {
        'name': 'Глеб', 
        'sername': 'Кисегач', 
        'father_name': 'Викторович', 
        'email': 'gleb@mail.', 
        'telefone_number': '2-87-98',
        'information': {'birthday': null,' interests': ['компьютерные игры', 'плавание', 'стрельба из лука']},
        'prikaz': {
			"Номер распоряжения": 333
		}
    },
    {
        'name': 'Варя', 
        'sername': 'Черноус', 
        'father_name': 'Петрович', 
        'email': 'cher@mail.ru', 
        'telefone_number': null,
        'information': {'birthday': '1980-01-14',' interests': ['борьба', 'книги', 'футбол']},  
        'prikaz': {
			"Номер приказа": 1
		}
    },
]);

