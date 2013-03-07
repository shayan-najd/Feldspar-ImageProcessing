{-# OPTIONS_GHC -F -pgmF qapp #-}
module IP where
  
import qualified Prelude as P
import Feldspar
import Feldspar.Compiler
import Feldspar.Vector

-- Conversion from grayscale to black & white 
toBW :: Vector (Data Int32) -> Vector (Data Int32)
toBW = map (\x -> condition (x < 200) 1 0) 
       -- threshold is set to 200

-- The standard red channel grayscale coefficient
redCoefficient :: Data Float
redCoefficient =  0.30

-- The standard green channel grayscale coefficient
greenCoefficient :: Data Float
greenCoefficient =  0.59

-- The standard blue channel grayscale coefficient
blueCoefficient :: Data Float
blueCoefficient =  0.11

-- Conversion from RGB to grayscale
rgbToGray :: Data Int32 -> Data Int32 -> 
             Data Int32 -> Data Int32 
rgbToGray r g b =  truncate $ 
    (i2f r) *   redCoefficient
  + (i2f g) * greenCoefficient  
  + (i2f b) *  blueCoefficient              

-- Conversion from colored to grayscale       
toGray :: Vector (Data Int32) -> Vector (Data Int32)
toGray v = forLoop ((length v) `div` 3) Empty 
  (\ i acc -> let b = i * 3 in 
    acc ++ indexed 1 
    (const $ rgbToGray (v ! b) (v ! (b+1)) (v ! (b+2))))

-- Conversion from colored to black and white
fromColoredtoBW :: Vector (Data Int32) -> 
                   Vector (Data Int32)
fromColoredtoBW = toBW . toGray

compileFromColoredToBW :: IO ()
compileFromColoredToBW = 
  compile fromColoredtoBW 
  "fromColoredToBW" 
  "fromColoredToBW" defaultOptions 

compileToBW :: IO ()
compileToBW = 
  compile toBW 
  "toBW" 
  "toBW" defaultOptions 

compileToGray :: IO ()
compileToGray = 
  compile toGray
  "toGray" 
  "toGray" defaultOptions 
