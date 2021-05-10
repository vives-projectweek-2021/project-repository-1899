import express, { Application, Request, Response } from 'express'
import dotenv from 'dotenv'


dotenv.config()

const app: Application = express()

app.use(express.json());

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Methods', 'GET, POST, DELETE, OPTIONS, HEAD')
  next();
});

let value: number = 0.0;

  
  app.get('/api', async (request: Request, response: Response) => {
    response.json(value)
  })

  app.post('/api', async (request: Request, response: Response) => {
      value += request.body.value
       console.log(request.body)
    response.json({ result: 'OK '})
    
  })

  app.delete('/api', async (request: Request, response: Response) => {
    value = 0
    response.json({ result: 'OK '})
  })

  


app.listen(8080, () => {
  console.log("Listing")
})