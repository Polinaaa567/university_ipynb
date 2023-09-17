db.students.insertMany([{ 'last_name': 'Maloshtanova', 'name': 'Olga', 
                            'patronymic': 'Alekseevna', 'year of birth': 2003,'course':3, 
                            'direction of study': 'Фундаментальная информатика и информационные технологии',
                            'group':'ФИТ-211', 'language': ['english', 'Chinese'] , 'studied disciplines': [{
                                'name':'Mathematical analysis', 'semester': 1, 'assessment':4
                            }, {'name':'Architecture of computing systems', 'semester': 1, 'assessment':5 },
                        {'name':'English language', 'semester': 3, 'assessment':4 }]
                        }, 
                        { 'last_name': 'Sheps', 'name': 'Oleg', 
                            'patronymic': 'Viktorovich', 'year of birth': 2005,'course': 1, 
                            'direction of study': 'Прикладная математика и информатика',
                            'group':'ПМИ-231', 'language': ['english', 'russian'] , 'studied disciplines': [{
                                'name':'Mathematical analysis', 'semester': 1, 'assessment':5
                            }, {'name':'History', 'semester': 1, 'assessment':3 },
                                {'name':'Russian language', 'semester': 2, 'assessment':3 }]
                        },  
                        { 'last_name': 'Sheps', 'name': 'Alexander', 
                        'patronymic': 'Viktorovich', 'year of birth': 2004,'course':2, 
                        'direction of study': 'Математическое обеспечение и администрирование информационных систем',
                        'group':'МОА-221', 'language': ['German', 'Chinese'] , 'studied disciplines': [{
                            'name':'Differential equations', 'semester': 1, 'assessment':5
                        }, {'name':'Architecture of computing systems', 'semester': 2, 'assessment':5 },
                    {'name':'German language', 'semester': 2, 'assessment':5 }]
                    }, 
                    { 'last_name': 'Raydos', 'name': 'Viktoria', 
                    'patronymic': 'Stepanovna', 'year of birth': 2002,'course':4, 
                    'direction of study': 'Прикладная информатика',
                    'group':'ПИ-204', 'language': ['korean', 'Turkish'] , 'studied disciplines': [{
                        'name':'Operating systems', 'semester': 5, 'assessment': 3
                    }, {'name':'Architecture of computing systems', 'semester': 1, 'assessment': 4 },
                {'name':'Turkish language', 'semester': 6, 'assessment': 5 }]
                } ])