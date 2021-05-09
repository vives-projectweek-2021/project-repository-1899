import express, { Application, Request, Response } from 'express'
import dotenv from 'dotenv'


dotenv.config()

const app: Application = express()

app.use(express.json());

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  next();
});

let value: number = 0.0;

  
  app.get('/api', async (request: Request, response: Response) => {
    response.json(value)
  })

  app.post('/api', async (request: Request, response: Response) => {
      value += request.body.value
    response.json({ result: 'OK '})
    
  })

  


app.listen(8080, () => {
  console.log("Listing")
})