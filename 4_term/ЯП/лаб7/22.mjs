async function load() {
    let readConfig = await import('./22readconfig/readConfig.mjs')
    let doQuery = await import('./22doQuery/doQuery.mjs')
    let httpGet = await import('./22httpGet/httpGet.mjs')
    let readFile = await import('./22readFile/readFile.mjs')

    await readConfig.readConfig('myConfig')
    await doQuery.doQuery('select * from cities')
    await httpGet.httpGet('http://google.com')
    await readFile.readFile('README.md')

}

load()