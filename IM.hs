import qualified Prelude as P
import Feldspar
import Feldspar.Compiler
import Feldspar.Vector
import qualified System.IO.Unsafe as SU

logoPPM :: Vector (Data Int32)
logoPPM = let filePath = "Logo.ppm" 
  in SU.unsafePerformIO $ do 
    c <- readFile filePath
    let _:_:_:z = P.lines c
    let z'    = P.map ( fromInteger . 
                       (P.read :: String -> Integer))  z    
    return $ value z'    

logoPGM :: Vector (Data Int32)
logoPGM = let filePath = "Logo.pgm" 
  in SU.unsafePerformIO $ do 
    c <- readFile filePath
    let _:_:_:z = P.lines c
    let z'    = P.map ( fromInteger . (P.read :: String -> Integer))  z    
    return $ value  z'

compileLogoPPM :: IO ()
compileLogoPPM = compile logoPPM "logoPPM" "logoPPM" defaultOptions 

compileLogoPGM :: IO ()
compileLogoPGM = compile logoPGM "logoPGM" "logoPGM" defaultOptions 
 