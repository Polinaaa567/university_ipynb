db.news.insertMany([
    {
        title: 'New News',
        author: 'John Smith',
        date: new Date("1990-03-03T16:00:00Z"), 
        url: 'http://vdsvs/domain.ru',
        tags: ['Путешествие', 'Танцы'], 
        comments:[{
            user_name: 'Foo',
            email: 'foo@bar.com',
            number: '8(987)768-34-44', 
            text: 'uuuuu', 
            mark: 1
        }]
    }, 
    {
        title: 'New News 2',
        author: 'Tim Job',
        date: new Date("2005-06-07T16:00:00Z"), 
        url: 'http://vdjs/domain.ru',
        tags: ['Спорт', 'Футбол'], 
        comments:[{
            user_name: 'Timka',
            email: 'timcsj@gmail.com',
            number: '8(987)555-35-47', 
            text: 'cool', 
            mark: 5
        }, 
        {
            user_name: 'BHB',
            email: 'bhb@gmail.com',
            number: '8(937)545-55-47', 
            text: 'bmk', 
            mark: 7
        }]
    },{
        title: 'New News 3',
        author: 'Ponchik Kristall',
        date: new Date("2023-05-23T16:00:00Z"), 
        url: 'http://too/gygy.ru',
        tags: ['Музыка', 'Спорт'], 
        comments:[{
            user_name: 'Рын',
            email: 'rin@bar.com',
            number: '8(923)732-35-44', 
            text: 'uuuuu', 
            mark: 2
        }]
    },{
        title: 'New News 4',
        author: 'JN Yellow',
        date: new Date("2023-10-21T16:00:00Z"), 
        url: 'http://gnfk/domain.ru',
        tags: ['Медецина', 'Лекарства'], 
        comments:[{
            user_name: 'JBJN',
            email: 'vdks@bar.com',
            number: '8(986)788-34-32', 
            text: 'AAAA', 
            mark: 5
        }, {
            user_name: 'dvs',
            email: 'sd@bar.com',
            number: '8(987)788-34-32', 
            text: 'kkk', 
            mark: 4
        }]
    },{
        title: 'New News 5',
        author: 'Red Blue',
        date: new Date("1990-03-03T16:00:00Z"), 
        url: 'http://akw/domain.ru',
        tags: ['Путешествия', 'Танцы'], 
        comments:[{
            user_name: 'asnmk',
            email: 'asb@bar.com',
            number: '8(957)768-38-44', 
            text: 'uuuuu', 
            mark: 10
        }]
    }
])